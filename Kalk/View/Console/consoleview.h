#ifndef CONSOLEVIEW_H
#define CONSOLEVIEW_H
#include "../view.h"
#include <iostream>
class ConsoleView:public View{
private:
    QVector<QString> l_types;
    QVector<QString> r_types;
    int l_size;
    int r_size;
    QVector<QString> allOpts;
    QVector<QString> permittedOpts;
    QVector<QString> consoleInput(int n);
public slots:
    void setLeftTypes(const QVector<QString> types);
    void setRightTypes(const QVector<QString> types);
    void setLeftFields(const int& fields);
    void setRightFields(const int& fields);
    //void setResultFields(const int& fields);
    void setAvailableOperations(const QVector<QString> operations);
    void setPermittedOperations(const QVector<QString> operations);
    void setResult(const QVector<QString> result);
    //void ansIsSet(const QVector<QString> values);
    //void setNumPad();
    void show();
};

#endif // CONSOLEVIEW_H
