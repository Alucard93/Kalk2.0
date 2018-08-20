#include "model.h"

Model::Model(const Model* previous):old(previous){
    left=nullptr;
    right=nullptr;
    result=nullptr;
    alternativeRight=-10;
    availableTypes=ColorFactory::AllTypes;
}

Model::~Model(){

}

QVector<QString> Model::availableOperations(){
    return ColorFactory::availableOperations();
}

QVector<QString> Model::allAvailableTypes(){
    return availableTypes;
}

void Model::setLeftType(int type){
    leftType=availableTypes[type];
    left = ColorFactory::GetNewColor(type);
    emit leftSize(left->getNumberOfComponets());
    emit permittedOperations(left->availableOperations());
    emit update();

}

void Model::setLeftValues(QVector<QString> values){
    left->setComponents(qstring2double(values));
}

void Model::setRightType(int type){
    rightType=availableTypes[type];
    right = ColorFactory::GetNewColor(type);
    emit rightSize(right->getNumberOfComponets());
}

void Model::setRightValues(QVector<QString> values){
    right->setComponents(qstring2double(values));
}

void Model::setOp(int eOperation){
    operation = eOperation;
    QVector<QString> permitted = ColorFactory::typeByOperation(operation);
    emit rightTypes(permitted);
}

void Model::execute(){
    result = ColorFactory::Execution(left,operation,right);
}

void Model::getResult(){
    QVector<QString> result;
    QVector<double> r_component = this->result->getComponents();
    double component;
    foreach(component,r_component){
        result.push_back(QString::number(component));
    }
    emit resultReady(result);
}

QVector<double> Model::qstring2double(QVector<QString> values){
   QVector<double> toReturn;
   QString value;
   foreach(value, values){
       toReturn.push_back(value.toDouble());
   }
   return toReturn;
}
