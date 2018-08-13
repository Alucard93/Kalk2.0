#ifndef VIEW_H
#define VIEW_H
#include <QVector>
class View{
public:
    virtual void setAvTypes(QVector<QString> types)=0;
    virtual void setOperation(QVector<QString> operations)=0;
    virtual void printChoise(QString what)=0;
    virtual QVector<QString> getvalues()=0;
    virtual void printResult(QVector<QString> result)=0;
};

#endif // VIEW_H
