/**
 * @file model.h
 * @author Gianmarco Pettinato
 * @date 10/08/2018
 * @class Model
 * @brief this abstract class is used to connect the view
 * */
#include <QObject>
#ifndef MODEL_H
#define MODEL_H
class Model : public QObject{
    Q_OBJECT
public:
    virtual QVector<QString> availableOperations() const =0;
    virtual QVector<QString> allAvailableTypes() const =0;
    virtual Model* clone() const =0;
    virtual void setOld(const Model* model)=0;

public slots:
    virtual void setLeftType(QString type) =0;
    virtual void setLeftValues(QVector<QString> values) =0;
    virtual void setRightType(QString type) =0;
    virtual void setRightValues(QVector<QString> values) =0;
    virtual void setLastResultAsLeftOperand()=0;
    virtual void setOp(QString eOperation) =0;
    virtual void execute() =0;
    virtual void getResult() =0;
    virtual void getHistory() =0;
signals:
    void permittedOperations(QVector<QString> operations);
    void leftSize(int size);
    void rightSize(int size);
    void rightTypes(QVector<QString> permittedTypes);
    void resultReady(QVector<QString> result);
    void update();
    void history(QVector<QString> olds);
};

#endif // MODEL_H
