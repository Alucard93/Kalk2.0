#include "consoleview.h"
#include <iostream>

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

void ConsoleView::show(){

}

QVector<QString> ConsoleView::consoleInput(int n){
    QVector<QString> toReturn;
    while(toReturn.size()<=n){
        char c_string[64];
        std::cin>>c_string;
        toReturn.push_back(c_string);
    }
    return  toReturn;
}
