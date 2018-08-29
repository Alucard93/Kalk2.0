#include "consoleview.h"
#include <iostream>
#include <QApplication>


ConsoleView::ConsoleView(const ConsoleView& console){
    l_types=console.l_types;
    r_types=console.r_types;
    l_size=console.l_size;
    l_size=console.l_size;
}

void ConsoleView::setLeftTypes(const QVector<QString> types){
    l_types=types;
}

void ConsoleView::setRightTypes(const QVector<QString> types){
    r_types=types;
}
void ConsoleView::setLeftFields(const int& fields){
    l_size=fields;
}
void ConsoleView::setRightFields(const int& fields){
    r_size=fields;
}
void ConsoleView::setAvailableOperations(QVector<QString> opt){
    allOpts=opt;
}
void ConsoleView::setPermittedOperations(QVector<QString> opt){
    permittedOpts=opt;
}

void ConsoleView::setResult(QVector<QString> result){
    local_result=result;
}

void ConsoleView::setResultFields(const int& fields){
    //DO NOTHING
}

void ConsoleView::show(){
    showInConsole();
}

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
QVector<QString> ConsoleView::consoleInput(int n){

    QVector<QString> toReturn;
    while(toReturn.size()<n){
        char c_string[64];
        std::cin>>c_string;
        toReturn.push_back(c_string);
    }
    return  toReturn;
}

void ConsoleView::showString(const QVector<QString>& s_vector){
    QString line;
    foreach(line,s_vector){
        std::cout<<line.toStdString()<<'\n';
    }
}

void ConsoleView::update(){
    l_update=true;
}
