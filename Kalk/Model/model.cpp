#include "model.h"

Model::Model(const Model* previous):old(previous){
    left=nullptr;
    right=nullptr;
    result=nullptr;
    alternativeRight=-1;
    operation=-1;
    availableTypes=ColorFactory::AllTypes;
}

Model::~Model(){

}

QVector<QString> Model::availableOperations(){
    return ColorFactory::availableOperations();
}

QVector<QString> Model::allAvailableTypes(){
    return ColorFactory::typeByOperation(-1);
}

void Model::setLeftType(int type){
    if(type!=0){
        leftType=availableTypes[type-1];
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
        if(ColorFactory::typeByOperation(operation)[type]=="int"){
            rightType="int";
            emit rightSize(1);
        }else{
            rightType=availableTypes[type-1];
            right = ColorFactory::GetNewColor(type);
            emit rightSize(right->getNumberOfComponets());
            emit update();
        }
    }
}

void Model::setRightValues(QVector<QString> values){
    std::cout<<values[0].toStdString();
    if(!values.isEmpty() && rightType!="int"){
        right->setComponents(qstring2double(values));
        emit update();
    }else if(rightType=="int"){
        alternativeRight=values[0].toInt();
    }
}

void Model::setOp(QString eOperation){
    QVector<QString> avOp = left->availableOperations();
        int i=0;
        while(avOp[i]!=eOperation)
            i++;
        operation = i;
        QVector<QString> permitted = ColorFactory::typeByOperation(operation);
    emit rightTypes(permitted);
    emit update();
}

void Model::execute(){
    if(alternativeRight==-1)
        result = ColorFactory::Execution(left,operation,right);
    else
        result = ColorFactory::Execution(left,operation,alternativeRight);
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

QVector<QString> Model::getHistory(){
    QVector<QString> history;
    Model* oldIteration = const_cast<Model*>(old);
    int i=0;
    while(oldIteration!=nullptr){
        history.push_back("OP."+QString::number(i));
        if(oldIteration->left!=nullptr){
            history.push_back(oldIteration->leftType);
            history.push_back(oldIteration->left->getRappresentation());
        }
        history.push_back(oldIteration->left->availableOperations()[operation]);
        if(oldIteration->right!=nullptr){
            if(alternativeRight==-1){
                history.push_back(oldIteration->rightType);
                history.push_back(oldIteration->right->getRappresentation());
            }else{
                history.push_back("Intero");
                history.push_back(QString::number(alternativeRight));
            }
        }
        oldIteration = const_cast<Model*>(oldIteration->old);
    }
    return history;
}

QVector<double> Model::qstring2double(QVector<QString> values){
   QVector<double> toReturn;
   QString value;
   foreach(value, values){
       toReturn.push_back(value.toDouble());
   }
   return toReturn;
}
