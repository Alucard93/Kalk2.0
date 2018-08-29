#ifndef CONSOLEVIEW_H
#define CONSOLEVIEW_H
#include "../view.h"
#include <iostream>
class ConsoleView:public View{
private:
    void showInConsole();
    void showString(const QVector<QString>& s_vector);
    QVector<QString> l_types;
    QVector<QString> r_types;
    QVector<QString> local_result;
    int l_size;
    int r_size;
    QVector<QString> allOpts;
    QVector<QString> permittedOpts;
    QVector<QString> consoleInput(int n);
    bool l_update;
public:
    ConsoleView(View* parent=nullptr):View(parent){}
    ConsoleView(const ConsoleView& console);
    ~ConsoleView()=default;
public slots:
    void setAvailableOperations(const QVector<QString> operations);
    void setPermittedOperations(const QVector<QString> operations);
    void setLeftTypes(const QVector<QString> types);
    void setLeftFields(const int& fields);
    void setRightTypes(const QVector<QString> types);
    void setRightFields(const int& fields);
    void setResult(const QVector<QString> result);
    void setResultFields(const int& fields);
    void update();
    void show();
};

#endif // CONSOLEVIEW_H
