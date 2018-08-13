#ifndef MODEL_H
#define MODEL_H
#include <colorfactory.h>

class Model{
private:
    const Model* const old;
    Color* left;
    QString typeLeft;
    Color* right;
    QString typeRight;
    Color* result;
    QString operation;
    QVector<QString> availableOp;

public:
    Model(const Model* previous=nullptr);
    QVector<QString> availableOperation();// test the left operand for available operation
    QVector<QString> availableTypes();// test the left operand for available operation
    void setLeftType(QString type);
    void setLeftValues(QVector<double> values);
    void setRightType(QString type);
    void setRightValues(QVector<double> values);
    void setOP(int eOperation);
    void execute();
    QString getResult();
    ~Model();
};

#endif // MODEL_H
