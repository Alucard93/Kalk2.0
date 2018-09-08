/**
 * @file model.h
 * @author Gianmarco Pettinato
 * @date 10/08/2018
 * @class Model
 * @brief this abstract class is used by controller to be connected to the view
 * */
#include <QObject>
#ifndef MODEL_H
#define MODEL_H
class Model : public QObject{
    Q_OBJECT
public:
    virtual QVector<QString> availableOperations() const =0;
    virtual QVector<QString> allAvailableTypes() const =0;
    virtual ~Model()=default;

public slots:
    virtual void setLeftType(QString type) =0;
    virtual void setLeftValues(QVector<QString> values) =0;
    virtual void setRightType(QString type) =0;
    virtual void setRightValues(QVector<QString> values) =0;
    virtual void setResultType(QString type) =0;
    virtual void setOp(QString eOperation) =0;
    virtual void execute() =0;
    virtual void getResult() =0;
    virtual void getHistory() =0;
    virtual void reset() =0;
signals:
    void permittedOperations(QVector<QString> operations);
    void leftSize(int size, const QVector<QString>& limits);
    void rightSize(int size, const QVector<QString>& limits);
    void rightTypes(QVector<QString> permittedTypes);
    void resultSize(int size);
    void resultReady(QVector<QString> result);
    void history(const QVector<QVector<QString>>& historyVector);
    void error(QString);
    void resetTypeAt(QString drop,QString type);
};

#endif // MODEL_H
