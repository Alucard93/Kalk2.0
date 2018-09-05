#include "colormodel.h"

QVector<const ColorModel*> ColorModel::localHistory={};
QVector<QString> ColorModel::availableOp={};
QVector<QString> ColorModel::availableTypes={};
/**
 * @brief Model::Model inizialize the ColorModel and assign the older ColorModel if exists
 * @param previous
 */

ColorModel::ColorModel()
{
    leftType="none";
    rightType="none";
    left=nullptr;
    right=nullptr;
    result=nullptr;
    alternativeRight=-1;
    operation=-1;
    availableTypes=ColorFactory::getAllColorTypes();
}

ColorModel::~ColorModel()
{
    const ColorModel* toDelete;
    foreach(toDelete,localHistory){
        if(toDelete->left!=nullptr){
            delete toDelete->left;
        }
        if(toDelete->right!=nullptr){
            delete toDelete->right;
        }
        if(toDelete->result!=nullptr){
            delete toDelete->result;
        }
        localHistory.pop_front();
    }
    if(left!=nullptr){
        delete left;
    }
    if(right!=nullptr){
        delete right;
    }
    if(result!=nullptr){
        delete result;
    }
}

/**
 * @brief ColorModel::availableOperations
 * @return QVector<QString> that contains all the operation that are available
 */
QVector<QString> ColorModel::availableOperations() const
{
    return ColorFactory::availableOperations();
}

/**
 * @brief ColorModel::allAvailableTypes
 * @return QVector<QString> that contains all permitted types
 */
QVector<QString> ColorModel::allAvailableTypes() const
{
    return ColorFactory::typeByOperation(-1);
}

/**
 * @brief ColorModel::setLeftType
 * @param type
 * setup the left operand type
 */
void ColorModel::setLeftType(QString type)
{
    if(left!=nullptr)
        delete left;
    if(ColorFactory::typeByOperation(-1).contains(type)){
        leftType=type;
        try{
            left = ColorFactory::getNewColor(type);
        } catch(IllegalColorException& e){
            emit error(e.what());
        }
        emit leftSize(left->getNumberOfComponets());
        emit permittedOperations(left->availableOperations());
    }
}

/**
 * @brief ColorModel::setLeftValues
 * @param values
 * set values to the left operand
 */
void ColorModel::setLeftValues(QVector<QString> values)
{
    try{
        left->setComponents(qstring2double(values));
    } catch(IllegalColorException& e){
        emit error(e.what());
    }
}

/**
 * @brief ColorModel::setRightType
 * @param type
 * set the right operand type
 */
void ColorModel::setRightType(QString type)
{
    if(right!=nullptr){
        delete right;
    }
    if(ColorFactory::typeByOperation(-1).contains(type) || type=="int"){
        rightType=type;
        if(rightType=="int")
            emit rightSize(1);
        else{
            try {
                right = ColorFactory::getNewColor(type);
            } catch (IllegalColorException& e) {
                emit error(e.what());
            }
            right = ColorFactory::getNewColor(type);
            emit rightSize(right->getNumberOfComponets());
        }
    }
}

/**
 * @brief ColorModel::setRightValues
 * @param values
 * set values to the right operand
 */

void ColorModel::setRightValues(QVector<QString> values)
{
    if(!values.isEmpty() && rightType!="int"){
        try {
            right->setComponents(qstring2double(values));
        } catch (IllegalColorException& e) {
            emit error(e.what());
        }

        emit update();
    }else if(rightType=="int"){
        alternativeRight=values[0].toInt();
    }
}

/**
 * @brief ColorModel::setOp
 * @param eOperation
 * set up the operation that will be executed
 */
void ColorModel::setOp(QString eOperation)
{
    QVector<QString> avOp = left->availableOperations();
    int i=0;
    while(avOp[i]!=eOperation)
        i++;
    operation = i;
    QVector<QString> permitted = ColorFactory::typeByOperation(operation);
    emit rightTypes(permitted);
    emit update();
}
/**
 * @brief ColorModel::execute
 * execute the operation
 */
void ColorModel::execute()
{
    try {
        if(result!=nullptr)
            delete result;
        if(rightType!="int")
            result = ColorFactory::execution(left,operation,right);
        else
            result = ColorFactory::execution(left,operation,alternativeRight);
    } catch (IllegalColorException& e) {
        emit error(e.what());
    }
}

/**
 * @brief ColorModel::getResult
 * set up result object
 */
void ColorModel::getResult()
{
    execute();
    if(result==nullptr)
        emit error("Bisogna selezionare un'operazione");
    else {
        QVector<QString> stringresult = double2qstring(result->getComponents());
        localHistory.push_front(this->clone());
        emit resultReady(stringresult);
    }
    emit update();
}

/**
 * @brief ColorModel::getHistory
 * @return QVector<QString> with the history of the operation that has been done
 */
void ColorModel::getHistory()
{
    QVector<QVector<QString>> toReturn={};
    const ColorModel* model;
    foreach(model, localHistory){
        toReturn.push_back(model->toString());
    }
    emit history(toReturn);
}


void ColorModel::reset(){
    left=nullptr;
    right=nullptr;
    result=nullptr;
    alternativeRight=-1;
    operation=-1;
}

/**
 * @brief ColorModel::qstring2double
 * @param values
 * @return QVector<double> with the QString values converted to double
 */
QVector<double> ColorModel::qstring2double(const QVector<QString>& values) const
{
    QVector<double> toReturn;
    QString value;
    foreach(value, values){
        toReturn.push_back(value.toDouble());
    }
    return toReturn;
}
/**
 * @brief ColorModel::double2qstring
 * @param values
 * @return a Vector of Strings converted from a Vector of doubles
 * returns a Vector of Strings converted from a Vector of doubles
 */
QVector<QString> ColorModel::double2qstring(const QVector<double>& values) const{
    QVector<QString> toReturn;
    double value;
    foreach(value,values)
        toReturn.push_back(QString::number(value));
    return toReturn;
}

/**
 * @brief ColorModel::clone
 * @return a clone of the current ColorModel;
 */
const ColorModel* ColorModel::clone() const{
    ColorModel* model = new ColorModel();
    if(this->leftType!="none"){
        model->leftType=this->leftType;
        model->left = ColorFactory::cloneColor(left);
    }
    if(this->rightType!="none"){
        model->rightType=this->rightType;
        if(this->rightType!="int"){
            model->right = ColorFactory::cloneColor(right);
        }else{
            model->alternativeRight=this->alternativeRight;
        }
    }
    model->operation=this->operation;

    if(this->result!=nullptr){

        model->result = ColorFactory::cloneColor(result);
    }
    return model;

}

/**
 * @brief ColorModel::toString
 * @return Vector made of String that contains ColorModel in string format
 */
QVector<QString> ColorModel::toString() const{
    QVector<QString> vectorString={};
    if(left!=nullptr) // add left operand data
    {
        vectorString.push_back(leftType);
        vectorString+=(double2qstring(left->getComponents()));
    }

    if(operation!=-1)
        vectorString.push_back(left->availableOperations()[operation]); //adds operation string to the operation
    else
        vectorString.push_back("operation not set");

    if(rightType!="none"){
        if(right!=nullptr && rightType!="int")
        {
            vectorString.push_back(rightType);
            vectorString+=(double2qstring(right->getComponents()));
        }else
        {
            vectorString.push_back("Intero");
            vectorString.push_back(QString::number(alternativeRight));
        }
    }
    if(result!=nullptr){
        vectorString.push_back(leftType);
        vectorString+=double2qstring(result->getComponents());

    }
    return vectorString;
}
