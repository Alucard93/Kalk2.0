#include "./controller.h"
#include <iostream>
Controller::Controller(Model* f_model, View* f_view){
    model = f_model;
    view = f_view;
    connectView();
    setViewAvailableTypes();
    view->show();
}

void Controller::setViewAvailableTypes(){
    view->setAvailableTypes(model->availableTypes());
}

void Controller::setLeftType(QString type){
    std::cout<<"Funziona come pensi"<<'\n';
    model->setLeftType(type);
    QVector<QString> ops = model->availableOperation();
    QString op;
    foreach(op, ops){
        std::cout<<op.utf16();
    }
    //view->setOperation();
}

void Controller::setLeftValue(QVector<QString> values){
    QVector<double> modelValues;
    QString value;
    foreach(value, values){
        modelValues.push_back(value.toDouble());
    }
    model->setLeftValues(modelValues);
}

void Controller::setRightType(QString type){
    model->setRightType(type);
    QVector<QString> ops = model->availableOperation();
    QString op;
    //view->setOperation();
}

void Controller::setRightValue(QVector<QString> values){
    QVector<double> modelValues;
    QString value;
    foreach(value, values){
        modelValues.push_back(value.toDouble());
    }
    model->setRightValues(modelValues);
}

void Controller::setOperation(int operation){
    model->setOP(operation);
}

void Controller::getResult(){

}

void Controller::getOld(){

}

void Controller::connectView(){
    QObject::connect(view,SIGNAL(leftTypeIsSet(QString)),this,SLOT(setLeftType(QString)));
    QObject::connect(view,SIGNAL(rightTypeIsSet(QString)),this,SLOT(setRightType(QString)));
}
