#ifndef MODEL_H
#define MODEL_H
#include <colorfactory.h>
#include

class Model{
private:
    const Model* const old;
    Color* left;
    Color* right;
    Color* result;
    QString operation;
    QVector<QString> availableOp;

public:
    Model(const Model* previous=nullptr);
    QVector<QString> availableOperation();// test the left operand for available operation
    QVector<QString> availableTypes();// test the left operand for available operation
    void setLeftOperand(QString type, QVector<double> data);
    void setRightOperand(QString type, QVector<double> data);
    void setOP(int eOperation);
    void execute();
    QString getResult();
    ~Model();
};

#endif // MODEL_H
