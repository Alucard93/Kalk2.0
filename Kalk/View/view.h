#ifndef VIEW_H
#define VIEW_H
#include <QVector>
#include <QObject>
class View: public QObject{
     Q_OBJECT
public:
    virtual void setAvailableTypes(const QVector<QString> types) =0;
    virtual void setAvailableOperations(const QVector<QString> operations) =0;
    virtual void setPermittedOperations(const QVector<QString> operations)=0;
    virtual void setRightTypes(const QVector<QString> types)=0;
    virtual void setResult(const QVector<QString> result)=0;
    virtual void show()=0;
signals:
    void leftValuesAreSet(QVector<QString> values);
    void rightValuesAreSet(QVector<QString> values);
    void leftTypeIsSet(QString type);
    void rightTypeIsSet(QString type);
    void operationIsSet(QString type);
    void getResult();
};

#endif // VIEW_H
