#ifndef MODEL_H
#define MODEL_H
#include <QString>
#include <QObject>
#include <QVariant>
#include "Color/colorfactory.h"

class Model: public QObject{
    Q_OBJECT
private:
    const Model* const old;
    Color* left;
    QString leftType;
    Color* right;
    int alternativeRight;
    QString rightType;
    Color* result;
    int operation;
    QVector<QString> availableOp;
    QVector<QString> availableTypes;

public:
    Model(const Model* previous=nullptr);
    ~Model();
    QVector<QString> availableOperations();
    QVector<QString> allAvailableTypes();

public slots:
    void setLeftType(QString type);
    void setLeftValues(QVector<QString> values);
    void setRightType(QString type);
    void setRightValues(QVector<QString> values);
    void setOp(QString eOperation);
    void execute();
    void getResult();

signals:
    void permittedOperations(QVector<QString> operations);
    void leftSize(int size);
    void rightSize(int size);
    void rightTypes(QVector<QString> permittedTypes);
    void resultReady(QVector<QString> result);
    void update();
private:
    QVector<double> qstring2double(QVector<QString> value);
};

#endif // MODEL_H
