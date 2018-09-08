#include "./controller.h"
#include <iostream>
/**
 * @brief Controller::Controller
 * @param f_model
 * @param f_view
 */
Controller::Controller(Model* f_model, View* f_view){
    model = f_model;
    view = f_view;
    setUp();
    connect();
}

/**
 * @brief Controller::~Controller
 */
Controller::~Controller(){
    disconnect();
    delete model;
    delete view;
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
    QObject::connect(model,SIGNAL(leftSize(int,const QVector<QString>&)),view,SLOT(setLeftFields(int,const QVector<QString>&)));
    QObject::connect(model,SIGNAL(rightSize(int,const QVector<QString>&)),view,SLOT(setRightFields(int,const QVector<QString>&)));
    QObject::connect(model,SIGNAL(rightTypes(QVector<QString>)),view,SLOT(setRightTypes(QVector<QString>)));
    QObject::connect(model,SIGNAL(resultReady(QVector<QString>)),view,SLOT(setResult(QVector<QString>)));
    QObject::connect(model,SIGNAL(leftSize(int,const QVector<QString>&)),view,SLOT(setResultFields(int)));
    QObject::connect(model,SIGNAL(resultSize(int)),view,SLOT(setResultFields(int)));
    QObject::connect(view,SIGNAL(resultTypeIsSet(QString)),model,SLOT(setResultType(QString)));
    QObject::connect(view,SIGNAL(getHistory()),model,SLOT(getHistory()));
    QObject::connect(model,SIGNAL(history(const QVector<QVector<QString>>&)),view,SLOT(setHistory(const QVector<QVector<QString>>&)));
    QObject::connect(view,SIGNAL(reset()),model,SLOT(reset()));
    QObject::connect(view,SIGNAL(reset()),this,SLOT(setUp()));
    QObject::connect(model,SIGNAL(error(const QString&)),view,SLOT(error(const QString&)));
    QObject::connect(model,SIGNAL(resetTypeAt(QString,QString)),view,SLOT(resetType(QString , QString)));
}

/**
 * @brief Controller::disconnect
 * disconnects all the slots and signal in view and model
 */

void Controller::disconnect(){
    QObject::disconnect(view,SIGNAL(leftTypeIsSet(QString)),model,SLOT(setLeftType(QString)));
    QObject::disconnect(view,SIGNAL(rightTypeIsSet(QString)),model,SLOT(setRightType(QString)));
    QObject::disconnect(view,SIGNAL(leftValuesAreSet(QVector<QString>)),model,SLOT(setLeftValues(QVector<QString>)));
    QObject::disconnect(view,SIGNAL(rightValuesAreSet(QVector<QString>)),model,SLOT(setRightValues(QVector<QString>)));
    QObject::disconnect(view,SIGNAL(operationIsSet(QString)),model,SLOT(setOp(QString)));
    QObject::disconnect(view,SIGNAL(getResult()),model,SLOT(getResult()));
    QObject::disconnect(model,SIGNAL(permittedOperations(QVector<QString>)),view,SLOT(setPermittedOperations(QVector<QString>)));
    QObject::disconnect(model,SIGNAL(leftSize(int,const QVector<QString>&)),view,SLOT(setLeftFields(int,const QVector<QString>&)));
    QObject::disconnect(model,SIGNAL(rightSize(int,const QVector<QString>&)),view,SLOT(setRightFields(int,const QVector<QString>&)));
    QObject::disconnect(model,SIGNAL(rightTypes(QVector<QString>)),view,SLOT(setRightTypes(QVector<QString>)));
    QObject::disconnect(model,SIGNAL(resultReady(QVector<QString>)),view,SLOT(setResult(QVector<QString>)));
    QObject::disconnect(model,SIGNAL(leftSize(int,const QVector<QString>&)),view,SLOT(setResultFields(int)));
    QObject::disconnect(model,SIGNAL(resultSize(int)),view,SLOT(setResultFields(int)));
    QObject::disconnect(view,SIGNAL(resultTypeIsSet(QString)),model,SLOT(setResultType(QString)));
    QObject::disconnect(view,SIGNAL(getHistory()),model,SLOT(getHistory()));
    QObject::disconnect(model,SIGNAL(history(const QVector<QVector<QString>>&)),view,SLOT(setHistory(const QVector<QVector<QString>>&)));
    QObject::disconnect(view,SIGNAL(reset()),model,SLOT(reset()));
    QObject::disconnect(view,SIGNAL(reset()),this,SLOT(setUp()));
    QObject::disconnect(model,SIGNAL(error(const QString&)),view,SLOT(error(const QString&)));
    QObject::disconnect(model,SIGNAL(resetTypeAt(QString,QString)),view,SLOT(resetType(QString , QString)));
}
