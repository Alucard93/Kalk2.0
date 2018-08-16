#ifndef CONSOLEVIEW_H
#define CONSOLEVIEW_H
#include "../view.h"
#include <iostream>
class ConsoleView:public View{
private:
    QVector<QString> l_types;
    QVector<QString> r_types;
    QVector<QString> opts;
    QVector<QString> consoleInput(int n);
public slots:
    void setAvailableTypes(QVector<QString> types);
    void setAvailableOperations(QVector<QString> operations);
    void setPermittedOperations(const QVector<QString> operations);
    void setRightTypes(const QVector<QString> types);
    void show();
    void setResult(QVector<QString> result);
    void setValues(bool left=true);
    void setType(bool left=true);
    void setOperation();
};

#endif // CONSOLEVIEW_H
