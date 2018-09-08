/**
 * @file view.h
 * @authors Giuseppe Bitetti & Gianmarco Pettinato
 * @date 20/08/2018
 * @brief abstract class used as base reference for build a view class
 * */

#ifndef VIEW_H
#define VIEW_H
#include <QVector>
#include <QWidget>
class View: public QWidget{
     Q_OBJECT
public:
    View(QWidget* parent=nullptr):QWidget(parent){}
    virtual ~View()=default;
public slots:
    virtual void setAvailableOperations(const QVector<QString> operations) =0;
    virtual void setPermittedOperations(const QVector<QString> operations)=0;
    virtual void setLeftTypes(const QVector<QString> types) =0;
    virtual void setLeftFields(const int& fields, const QVector<QString>& limits) =0;
    virtual void setRightTypes(const QVector<QString> types) =0;
    virtual void setRightFields(const int& fields, const QVector<QString>& limits) =0;
    virtual void setResult(const QVector<QString> result)=0;
    virtual void setResultFields(const int& fields)=0;
    virtual void setHistory(const QVector<QVector<QString>>& history) =0;
    virtual void error(const QString& error_message) =0;
    virtual void resetType(QString drop, QString type) =0;
    virtual void show()=0;
signals:
    void leftValuesAreSet(QVector<QString> values);
    void rightValuesAreSet(QVector<QString> values);
    void leftTypeIsSet(QString type);
    void rightTypeIsSet(QString type);
    void resultTypeIsSet(QString type);
    void operationIsSet(QString opt);
    void getResult();
    void getHistory();
    void reset();
    void done();
};

#endif // VIEW_H
