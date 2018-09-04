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
    static QVector<const ColorModel*> localHistory;
    static QVector<QString> availableOp;
    static QVector<QString> availableTypes;
    const ColorModel* const old;
    Color* left;
    QString leftType;
    Color* right;
    int alternativeRight;
    QString rightType;
    Color* result;
    int operation;


public:
    //default constructor
    ColorModel(const Model* previous=nullptr);
    //default ddestructor
    ~ColorModel();

    QVector<QString> availableOperations() const;
    QVector<QString> allAvailableTypes() const;

public slots:
    void setLeftType(QString type);
    void setLeftValues(QVector<QString> values);
    void setRightType(QString type);
    void setRightValues(QVector<QString> values);
    void setOp(QString eOperation);
    void execute();
    void getResult();
    void getHistory();
    void reset();

private:
    const ColorModel* clone() const;
    QVector<double> qstring2double(const QVector<QString>& value) const;
    QVector<QString> double2qstring(const QVector<double>& values) const;
    QVector<QString> toString() const;
};

#endif // COLORMODEL_H
