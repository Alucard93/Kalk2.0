#ifndef CONSOLEVIEW_H
#define CONSOLEVIEW_H
#include <view.h>
#include <iostream>
class ConsoleView: public View{
private:
    QVector<QString> l_types;
    QVector<QString> opts;
public:
    void setAvTypes(QVector<QString> types);
    void setOperation(QVector<QString> operations);
    void printChoise(QString what);
    QVector<QString> getvalues();
    void printResult(QVector<QString> result);
};

#endif // CONSOLEVIEW_H
