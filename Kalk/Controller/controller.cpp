#include "./controller.h"
#include <iostream>
Controller::Controller(Model* f_model, View* f_view){
    model = f_model;
    view = f_view;
    setUp();
    connect();
}

/**
 * @brief Controller::setUp
 * set up the object view usign model information
 */
void Controller::setUp(){
    view->setLeftTypes(model->allAvailableTypes());
    view->setAvailableOperations(model->availableOperations());
}

/**
 * @brief Controller::newModel
 * Creates a new model keeping the old one
 */
void Controller::newModel(){
    model = new ColorModel(model);
    setUp();
    connect();
}

/**
 * @brief Controller::connect
 * Connects all the slots and signal in view and model
 */
void Controller::connect(){
    QObject::connect(view,SIGNAL(leftTypeIsSet(QString)),model,SLOT(setLeftType(QString)));
    QObject::connect(view,SIGNAL(rightTypeIsSet(QString)),model,SLOT(setRightType(QString)));
    QObject::connect(view,SIGNAL(leftValuesAreSet(QVector<QString>)),model,SLOT(setLeftValues(QVector<QString>)));
    QObject::connect(view,SIGNAL(rightValuesAreSet(QVector<QString>)),model,SLOT(setRightValues(QVector<QString>)));
    QObject::connect(view,SIGNAL(operationIsSet(QString)),model,SLOT(setOp(QString)));
    QObject::connect(view,SIGNAL(getResult()),model,SLOT(getResult()));
    QObject::connect(model,SIGNAL(permittedOperations(QVector<QString>)),view,SLOT(setPermittedOperations(QVector<QString>)));
    QObject::connect(model,SIGNAL(leftSize(int)),view,SLOT(setLeftFields(int)));
    QObject::connect(model,SIGNAL(rightSize(int)),view,SLOT(setRightFields(int)));
    QObject::connect(model,SIGNAL(rightTypes(QVector<QString>)),view,SLOT(setRightTypes(QVector<QString>)));
    QObject::connect(model,SIGNAL(resultReady(QVector<QString>)),view,SLOT(setResult(QVector<QString>)));
    QObject::connect(model,SIGNAL(leftSize(int)),view,SLOT(setResultFields(int)));
    QObject::connect(model,SIGNAL(update()),view,SLOT(update()));
    QObject::connect(view,SIGNAL(getHistory()),model,SLOT(getHistory()));
    QObject::connect(model,SIGNAL(history(const QVector<QVector<QString>>&)),view,SLOT(setHistory(const QVector<QVector<QString>>&)));
    QObject::connect(view,SIGNAL(reset()),model,SLOT(reset()));
    QObject::connect(view,SIGNAL(reset()),this,SLOT(setUp()));
    QObject::connect(model,SIGNAL(error(const QString&)),view,SLOT(error(const QString&)));
}
