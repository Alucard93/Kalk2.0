#include "./controller.h"
#include <iostream>
Controller::Controller(Model* f_model, View* f_view){
    model = f_model;
    view = f_view;
}

void Controller::setUp(){
    view->setLeftTypes(model->allAvailableTypes());
    view->setAvailableOperations(model->availableOperations());
}

void Controller::connect(){
    QObject::connect(view,SIGNAL(leftTypeIsSet(int)),model,SLOT(setLeftType(int)));
    QObject::connect(view,SIGNAL(rightTypeIsSet(int)),model,SLOT(setRightType(int)));
    QObject::connect(view,SIGNAL(leftValuesAreSet(QVector<QString>)),model,SLOT(setLeftValue(QVector<QString>)));
    QObject::connect(view,SIGNAL(rightValuesAreSet(QVector<QString>)),model,SLOT(setRightValue(QVector<QString>)));
    QObject::connect(view,SIGNAL(operationIsSet(int)),model,SLOT(setOp(int)));
    QObject::connect(view,SIGNAL(getResult()),model,SLOT(getResult()));
    QObject::connect(model,SIGNAL(permittedOperations(QVector<QString>)),view,SLOT(setPermittedOperations(QVector<QString>)));
    QObject::connect(model,SIGNAL(leftSize(int)),view,SLOT(setLeftFields(int)));
    QObject::connect(model,SIGNAL(rightSize(int)),view,SLOT(setRightFields(int)));
    QObject::connect(model,SIGNAL(rightTypes(QVector<QString>)),view,SLOT(setRightTypes(QVector<QString>)));
    QObject::connect(model,SIGNAL(resultReady(QString)),view,SLOT(setResult(QVector<QString>)));

}
