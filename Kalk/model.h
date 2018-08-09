#ifndef MODEL_H
#define MODEL_H
#include <color.h>
#include <cie_xyz.h>
#include <rgb.h>
#include <cymk.h>
#include <hsl.h>
#include <ycbcr.h>
#include <yuv.h>

class Model{
private:
    class Operand{
    public:
      Color* l_op;
      QString type;
      Operand(QString eType="none");
      void setData(const QVector<int>& data);

      ~Operand();
    };
    const Model* const old;
    Operand* left;
    Operand* right;
    Operand* result;
    QString operation;
    QVector<QString> availableOp;

public:
    Model(const Model* previous=nullptr);
    QVector<QString> availableOperation();// test the left operand for available operation
    void setLeftOperand(int type, const QVector<int>& data);
    void setRightOperand(int type,const QVector<int>& data);
    void setOP(int eOperation);
    void execute();
    void setResult();
    static QStringList availableTypes;
    ~Model();
};

#endif // MODEL_H
