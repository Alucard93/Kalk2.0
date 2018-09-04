/**
  * @file consoleview.h
  * @author Gianmarco Pettinato
  * @date 20/08/2018
  * @class ConsoleView
  * @brief ConsoleView exestends the View class
  * and provides an interface in terminal line
  * */
#include "../view.h"
#include <iostream>
#ifndef CONSOLEVIEW_H
#define CONSOLEVIEW_H
class ConsoleView:public View{
private:
    int l_size;
    int r_size; 
    bool l_update;

    QVector<QString> l_types;
    QVector<QString> r_types;
    QVector<QString> local_result;
    QVector<QString> allOpts;
    QVector<QString> permittedOpts;

    QVector<QString> consoleInput(int n);
    void showInConsole();
    void showString(const QVector<QString>& s_vector);

public:
    //Default constructor
    ConsoleView(View* parent=nullptr):View(parent){}
    //Copy constructor
    ConsoleView(const ConsoleView& console);
    //Default Destructor
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
    void setHistory(const QVector<QVector<QString>>& history);
    void error(const QString& error_message);
    void update();
    void show();
};

#endif // CONSOLEVIEW_H
