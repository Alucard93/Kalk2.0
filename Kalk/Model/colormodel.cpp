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
    leftType="non disponibile";
    rightType="non disponibile";
    left=nullptr;
    right=nullptr;
    result=nullptr;
    alternativeRight=-1;
    operation=-1;
    availableTypes=ColorFactory::getAllColorTypes();
    ok=true;
    resultRead=false;
    resultChangeDone = false;
}

/**
 * @brief ColorModel::~ColorModel
 * deletes all Color that ColorModel points to.
 */

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
    ColorFactory::destruct();
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
    return availableTypes;
}

/**
 * @brief ColorModel::setLeftType
 * @param type
 * setup the left operand type
 */
void ColorModel::setLeftType(QString type)
{
    reset();
    if(ColorFactory::typeByOperation(-1).contains(type)){
        leftType=type;
        try{
            left = ColorFactory::getNewColor(type);
        } catch(IllegalColorException& er){
            ok=false;
            emit error(er.what());
        }
        if(ok){
            emit leftSize(left->getNumberOfComponets(),left->getLimits());
            emit permittedOperations(left->availableOperations());
        }
    }
    setResultType(type);
}

/**
 * @brief ColorModel::setLeftValues
 * @param values
 * set values to the left operand
 */
void ColorModel::setLeftValues(QVector<QString> values)
{
    if(!values.empty())
    {
        try{
            left->setComponents(qstring2double(values));
        } catch(IllegalColorException& e){
            ok = false;
            emit error(e.what());
        }
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
        right = nullptr;
    }
    if(ColorFactory::typeByOperation(-1).contains(type) || type=="intero"){
        rightType=type;
        if(rightType=="intero")
            emit rightSize(1,{"Numero","1","255"});
        else{
            try {
                right = ColorFactory::getNewColor(type);
            } catch (IllegalColorException& e) {
                ok=false;
                emit error(e.what());
            }
            emit rightSize(right->getNumberOfComponets(),right->getLimits());
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
    if(!values.isEmpty())
    {

        if(!values.isEmpty() && rightType!="intero"){
            try {
                right->setComponents(qstring2double(values));
            } catch (IllegalColorException& e) {
                ok = false;
                emit error(e.what());
            }


        }else if(rightType=="intero"){
            if(values[0].toInt()>255 || values[0].toInt()<1)
                emit error("il valore intero inserito non è valido");
            else
                alternativeRight=values[0].toInt();
        }
    }
}

/**
 * @brief ColorModel::setResultType set the result type
 * @param type
 */

void ColorModel::setResultType(QString type){
    bool toEmit = false;
    if(ColorFactory::typeByOperation(-1).contains(type))
    {
        Color* tmp = result;
        try
        {

            resultType=type;
            if(result && resultRead)
            {
                if(resultChangeDone)
                    throw IllegalColorException("Cambiare il tipo di ritorno più di una volta porta troppi errori di approssimazione ¯\\_(ツ)_/¯");
                result = ColorFactory::getNewColor(type,tmp);
                delete tmp;
                toEmit = true;
                localHistory.push_front(this->clone());
                resultChangeDone=true;
            }
            else if(!resultRead)
            {
                if(result)
                {
                    delete result;
                    result = nullptr;
                }
                result = ColorFactory::getNewColor(type);
                toEmit = false;
            }
        } catch(IllegalColorException& er){
            ok=false;
            result = tmp;
            emit error(er.what());
            resultType=typeid(*result).name()+1;
            emit resetTypeAt("Type_Result",resultType);
        }
        if(ok){
            emit resultSize(result->getNumberOfComponets());
            if(toEmit)
                emit resultReady(double2qstring(result->getComponents()));
        }

    }
}

/**
 * @brief ColorModel::setOp
 * @param eOperation
 * set up the operation that will be executed
 */
void ColorModel::setOp(QString eOperation)
{
    resultRead=false;
    QVector<QString> avOp = left->availableOperations();
    int i=0;
    while(avOp[i]!=eOperation)
        i++;
    operation = i;
    QVector<QString> permitted = ColorFactory::typeByOperation(operation);
    emit rightTypes(permitted);

}
/**
 * @brief ColorModel::execute
 * execute the operation
 */
void ColorModel::execute()
{
    Color* tmp = nullptr;
    if(result!=nullptr){
        delete result;
        result = nullptr;
    }
    if(ok)
    {
        try
        {
            if(rightType!="intero")
                tmp = ColorFactory::execution(left,operation,right);
            else
                tmp = ColorFactory::execution(left,operation,alternativeRight);
            if(resultType!=leftType){
                result = ColorFactory::getNewColor(resultType,tmp);
                delete tmp;
            }else{
                result = tmp;
            }
        } catch (IllegalColorException& e)
        {
            emit error(e.what());
        }

    }
    ok=true;
}

/**
 * @brief ColorModel::getResult
 * set up result object
 */
void ColorModel::getResult()
{
    if(left!=nullptr){
        execute();
        if(operation==-1)
            emit error("Bisogna selezionare un'operazione");
        else if(result==nullptr)
            emit error("Qualcosa è andato storto ¯\\_(ツ)_/¯ ");
        else {
            QVector<QString> stringresult = double2qstring(result->getComponents());
            localHistory.push_front(this->clone());
            emit resultReady(stringresult);
        }
        resultRead=true;
    }

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

/**
 * @brief ColorModel::reset
 * resets the ColorModel instance objects
 */
void ColorModel::reset(){
    if(left!=nullptr){
        delete left;
        left=nullptr;
        leftType="non disponibile";
    }
    if(right!=nullptr){
        delete right;
        right=nullptr;
        rightType="non disponibile";
    }
    if(result!=nullptr){
        delete result;
        result=nullptr;
        resultType="non disponibile";
    }
    alternativeRight=-1;
    operation=-1;
    ok=true;
    resultRead = false;
    resultChangeDone = false;
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
    if(this->leftType!="non disponibile"){
        model->leftType=this->leftType;
        model->left = ColorFactory::cloneColor(left);
    }
    if(this->rightType!="non disponibile"){
        model->rightType=this->rightType;
        if(this->rightType!="intero"){
            model->right = ColorFactory::cloneColor(right);
        }else{
            model->alternativeRight=this->alternativeRight;
        }
    }
    model->operation=this->operation;

    if(this->result!=nullptr){
        model->resultType = resultType;
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
        vectorString.push_back("operazione non selezionata");

    if(rightType!="non disponibile"){
        if(right!=nullptr && rightType!="intero")
        {
            vectorString.push_back(rightType);
            vectorString+=(double2qstring(right->getComponents()));
        }else
        {
            vectorString.push_back("intero");
            vectorString.push_back(QString::number(alternativeRight));
        }
    }
    if(result!=nullptr){
        vectorString.push_back(resultType);
        vectorString+=double2qstring(result->getComponents());

    }
    return vectorString;
}
