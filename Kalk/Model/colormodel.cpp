#include "colormodel.h"
QVector<ColorModel*> ColorModel::history;

/**
 * @brief Model::Model inizialize the ColorModel and assign the older ColorModel if exists
 * @param previous
 */

ColorModel::ColorModel(const Model* previous)
{
    if(previous)
        history.push_back(reinterpret_cast<ColorModel*>(previous->clone()));
    else
        history.push_back(nullptr);
    left=nullptr;
    right=nullptr;
    result=nullptr;
    alternativeRight=-1;
    operation=-1;
    availableTypes=ColorFactory::getAllColorTypes();
}

ColorModel::ColorModel(const ColorModel& model){
    availableTypes=ColorFactory::getAllColorTypes();
    leftType = model.leftType;
    rightType = model.rightType;
    left = ColorFactory::GetNewColor(leftType);
    if(allAvailableTypes().contains(rightType))
        right = ColorFactory::GetNewColor(rightType);
    else
        right = nullptr;
    alternativeRight = model.alternativeRight;
    operation=model.operation;
}

ColorModel::~ColorModel()
{
    if(left!=nullptr)
        delete left;
    if(right!=nullptr)
        delete right;
    if(result!=nullptr)
        delete result;disconnect();
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

Model* ColorModel::clone() const {
    return new ColorModel(this);
}

void ColorModel::setOld(const Model* model){
    history.push_back(reinterpret_cast<ColorModel*>(model->clone()));
}

/**
 * @brief ColorModel::setLeftType
 * @param type
 * setup the left operand type
 */
void ColorModel::setLeftType(QString type)
{
    if(type!="Select type"){
        leftType=type;
        left = ColorFactory::GetNewColor(type);
        emit leftSize(left->getNumberOfComponets());
        emit permittedOperations(left->availableOperations());
        emit update();
    }
}

/**
 * @brief ColorModel::setLeftValues
 * @param values
 * set values to the left operand
 */
void ColorModel::setLeftValues(QVector<QString> values)
{
    left->setComponents(qstring2double(values));
    emit update();
}

/**
 * @brief ColorModel::setRightType
 * @param type
 * set the right operand type
 */
void ColorModel::setRightType(QString type)
{
    if(type!="Select type" && type!="none"){
        rightType=type;
        if(rightType=="int")
            emit rightSize(1);
        else{
            right = ColorFactory::GetNewColor(type);
            emit rightSize(right->getNumberOfComponets());
        }
        emit update();
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
        right->setComponents(qstring2double(values));
        emit update();
    }else if(rightType=="int"){
        alternativeRight=values[0].toInt();
    }
}

void ColorModel::setLastResultAsLeftOperand(){
    //TODO
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
    if(alternativeRight==-1)
        result = ColorFactory::Execution(left,operation,right);
    else
        result = ColorFactory::Execution(left,operation,alternativeRight);
}

/**
 * @brief ColorModel::getResult
 * set up result object
 */
void ColorModel::getResult()
{
    execute();
    QVector<QString> result;
    QVector<double> r_component = this->result->getComponents();
    double component;
    foreach(component,r_component)
    {
        result.push_back(QString::number(component));
    }
    emit resultReady(result);
    emit update();
}

/**
 * @brief ColorModel::getHistory
 * @return QVector<QString> with the history of the operation that has been done
 */
void ColorModel::getHistory()
{
    QVector<QString> l_history;
    ColorModel* oldIteration;
    int i=0;
    foreach(oldIteration,history)
    {
        l_history.push_back("OP."+QString::number(i));
        if(oldIteration->left!=nullptr)
        {
            l_history.push_back(oldIteration->leftType);
            l_history.push_back(oldIteration->left->getRappresentation());
        }
        l_history.push_back(oldIteration->availableOperations()[oldIteration->operation]);
        if(oldIteration->right!=nullptr)
        {
            if(alternativeRight==-1)
            {
                l_history.push_back(oldIteration->rightType);
                l_history.push_back(oldIteration->right->getRappresentation());
            }
            else
            {
                l_history.push_back("Intero");
                l_history.push_back(QString::number(alternativeRight));
            }
        }
    }
    emit Model::history(l_history);
}

/**
 * @brief ColorModel::qstring2double
 * @param values
 * @return QVector<double> with the QString values converted to double
 */
QVector<double> ColorModel::qstring2double(QVector<QString> values)
{
   QVector<double> toReturn;
   QString value;
   foreach(value, values){
       toReturn.push_back(value.toDouble());
   }
   return toReturn;
}
