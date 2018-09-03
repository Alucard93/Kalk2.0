/**
  * @file ColorModel.h
  * @author Gianmarco Pettinato
  * @class ColorModel
  * Implements the class Model in the context of color representation
  */
#include <QString>
#include <QVector>
#include "./model.h"
#include "Factory/colorfactory.h"
#ifndef COLORMODEL_H
#define COLORMODEL_H

class ColorModel: public Model{
private:
    static QVector<ColorModel*> history;
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
    //default constructor
    ColorModel(const Model* previous=nullptr);
    ColorModel(const ColorModel& model);
    //default destructor
    ~ColorModel();

    QVector<QString> availableOperations() const;
    QVector<QString> allAvailableTypes() const;
    Model* clone() const;
    void setOld(const Model* model);
public slots:
    void setLeftType(QString type);
    void setLeftValues(QVector<QString> values);
    void setRightType(QString type);
    void setRightValues(QVector<QString> values);
    void setLastResultAsLeftOperand();
    void setOp(QString eOperation);
    void execute();
    void getResult();
    void getHistory();
private:
    QVector<double> qstring2double(QVector<QString> value);
};

#endif // COLORMODEL_H
