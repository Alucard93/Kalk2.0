/**
  * @file consoleview.h
  * @author Gianmarco Pettinato
  * @date 20/08/2018
  * @class ConsoleView
  * @brief ConsoleView exestends the View class
  * Console provides an interface in terminal line
  * */
#include "../view.h"
#include <iostream>
#ifndef CONSOLEVIEW_H
#define CONSOLEVIEW_H
class ConsoleView:public View{
private:
    int l_size;
    int r_size; 
    int result_size;
    bool l_update;
    static QVector<QString> menu;

    QVector<QString> l_types;
    QVector<QString> r_types;
    QVector<QString> l_limits;
    QVector<QString> r_limits;
    QVector<QString> local_result;
    QVector<QString> allOpts;
    QVector<QString> permittedOpts;

    QVector<QString> consoleInput(int n, const QVector<QString>& limits={"no"});
    void newOperation();
    void showMenu();
    void showChoices(const QVector<QString>& s_vector);
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
    void setLeftFields(const int& fields, const QVector<QString>& limits);
    void setRightTypes(const QVector<QString> types);
    void setRightFields(const int& fields, const QVector<QString>& limits);
    void setResult(const QVector<QString> result);
    void setResultFields(const int& fields);
    void setHistory(const QVector<QVector<QString>>& history);
    void error(const QString& error_message);
    void resetType(QString drop, QString type);
    void show();
};

#endif // CONSOLEVIEW_H
