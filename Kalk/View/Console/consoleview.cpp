#include "consoleview.h"
#include <iostream>
#include <QApplication>


ConsoleView::ConsoleView(const ConsoleView& console){
    l_types=console.l_types;
    r_types=console.r_types;
    l_size=console.l_size;
    l_size=console.l_size;
}

/**
 * @brief ConsoleView::setLeftTypes
 * @param types
 * sets up l_types variable
 */
void ConsoleView::setLeftTypes(const QVector<QString> types){
    l_types=types;
}

/**
 * @brief ConsoleView::setRightTypes
 * @param types
 * sets up r_types variable
 */
void ConsoleView::setRightTypes(const QVector<QString> types){
    r_types=types;
}
/**
 * @brief ConsoleView::setLeftFields
 * @param fields
 * sets up l_size variable
 */
void ConsoleView::setLeftFields(const int& fields){
    l_size=fields;
}
/**
 * @brief ConsoleView::setRightFields
 * @param fields
 * sets up r_size variable
 */
void ConsoleView::setRightFields(const int& fields){
    r_size=fields;
}
/**
 * @brief ConsoleView::setAvailableOperations
 * @param opt
 * sets up all operations that are available not really required
 */
void ConsoleView::setAvailableOperations(QVector<QString> opt){
    allOpts=opt;
}
/**
 * @brief ConsoleView::setPermittedOperations
 * @param opt
 * sets up all operations that the user can execute
 */
void ConsoleView::setPermittedOperations(QVector<QString> opt){
    permittedOpts=opt;
}

/**
 * @brief ConsoleView::setResult
 * @param result
 * sets up local_result variable
 */
void ConsoleView::setResult(QVector<QString> result){
    local_result=result;
}

/**
 * @brief ConsoleView::setResultFields
 * @param fields
 * does nothing because the resultFields are the same as left operand
 */

void ConsoleView::setResultFields(const int& fields){
    //DO NOTHING
}
void ConsoleView::error(const QString& error_message){
    //TODO
}

/**
 * @brief ConsoleView::show
 * inizialize the view inside the terminal
 */

void ConsoleView::show(){
    showInConsole();
}

/**
 * @brief ConsoleView::showInConsole
 * Shows the interface inside a terminal
 */
void ConsoleView::showInConsole(){
    bool exit=false;
    std::string input;
    while (!exit) {
        showString(l_types);
        emit leftTypeIsSet(consoleInput(1).first());
        emit leftValuesAreSet(consoleInput(l_size));
        showString(permittedOpts);
        emit operationIsSet(consoleInput(1).first());
        if(r_types.last()!="none"){
            showString(r_types);
            emit rightTypeIsSet(consoleInput(1).first());
            emit rightValuesAreSet(consoleInput(r_size));
        }
        emit getResult();
        showString(local_result);
        std::cout<<"write exit to close the program otherwise just press enter"<<'\n';
        std::cin >> input;
        if(input=="exit")
            exit=true;
    }
}

/**
 * @brief ConsoleView::consoleInput
 * @param n
 * @return user input in QVector<QString>
 * used to read input from user
 */
QVector<QString> ConsoleView::consoleInput(int n){

    QVector<QString> toReturn;
    while(toReturn.size()<n){
        char c_string[64];
        std::cin>>c_string;
        toReturn.push_back(c_string);
    }
    return  toReturn;
}

/**
 * @brief ConsoleView::showString
 * @param s_vector
 * prints on screen the content inside a QVector<QString>
 */
void ConsoleView::showString(const QVector<QString>& s_vector){
    QString line;
    foreach(line,s_vector){
        std::cout<<line.toStdString()<<'\n';
    }
}

void ConsoleView::setHistory(const QVector<QVector<QString>>& history){
    //TODO
}

/**
 * @brief ConsoleView::update
 * useless
 */
void ConsoleView::update(){
    l_update=true;
}
