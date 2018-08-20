#ifndef VIEW_H
#define VIEW_H
#include <QVector>
#include <QWidget>
class View: public QWidget{
     Q_OBJECT
public:
    View(QWidget* parent=nullptr):QWidget(parent){}
    ~View(){}
public slots:
    virtual void setAvailableOperations(const QVector<QString> operations) =0;
    virtual void setPermittedOperations(const QVector<QString> operations)=0;
    virtual void setLeftTypes(const QVector<QString> types) =0;
    virtual void setLeftFields(const int& fields) =0;
    virtual void setRightTypes(const QVector<QString> types) =0;
    virtual void setRightFields(const int& fields) =0;
    virtual void setResult(const QVector<QString> result)=0;
    virtual void update() =0;
    virtual void show()=0;
signals:
    void leftValuesAreSet(QVector<QString> values);
    void rightValuesAreSet(QVector<QString> values);
    void leftTypeIsSet(int type);
    void rightTypeIsSet(int type);
    void operationIsSet(QString opt);
    void getResult();
    void reset();
    void lastOperation();
};

#endif // VIEW_H
