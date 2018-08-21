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
    if(type!=0){
        leftType=availableTypes[type];
        left = ColorFactory::GetNewColor(type);
        std::cout<<"arrivo fino a qui"<<'\n';
        emit leftSize(left->getNumberOfComponets());
        std::cout<<"arrivo fino a qui"<<'\n';
        emit permittedOperations(left->availableOperations());
        std::cout<<"arrivo fino a qui"<<'\n';
        emit update();
    }
}

void Model::setLeftValues(QVector<QString> values){
    left->setComponents(qstring2double(values));
    emit update();
}

void Model::setRightType(int type){
    if(type!=0){
        rightType=availableTypes[type];
        right = ColorFactory::GetNewColor(type);
        emit rightSize(right->getNumberOfComponets());
        emit update();
    }
}

void Model::setRightValues(QVector<QString> values){
    if(!values.isEmpty()){
        right->setComponents(qstring2double(values));
        emit update();
    }
}

void Model::setOp(QString eOperation){
    QVector<QString> avOp =left->availableOperations();
        int i=0;
        while(avOp[i]!=eOperation)
            i++;
        operation = i;
        QVector<QString> permitted = ColorFactory::typeByOperation(operation);
    emit rightTypes(permitted);
    emit update();
}

void Model::execute(){
    result = ColorFactory::Execution(left,operation,right);
}

void Model::getResult(){
    execute();
    QVector<QString> result;
    QVector<double> r_component = this->result->getComponents();
    double component;
    foreach(component,r_component){
        result.push_back(QString::number(component));
    }
    emit resultReady(result);
    emit update();
}

QVector<double> Model::qstring2double(QVector<QString> values){
   QVector<double> toReturn;
   QString value;
   foreach(value, values){
       toReturn.push_back(value.toDouble());
   }
   return toReturn;
}
