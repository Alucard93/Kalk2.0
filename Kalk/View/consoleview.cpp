#include "consoleview.h"
#include <iostream>

void ConsoleView::setAvailableTypes(QVector<QString> Types){
    l_types=Types;
}
void ConsoleView::setAvailableOperations(QVector<QString> Operations){
    opts=Operations;
}
void ConsoleView::show(){
    setType();
}

void ConsoleView::setResult(QVector<QString> result){
    std::cout<<"Result"<<'\n';
}
void ConsoleView::setValues(bool left){
    QVector<QString> toSet;
    //input function
    if(left)
        emit(leftValuesAreSet(toSet));
    else
        emit(leftValuesAreSet(toSet));
}

void ConsoleView::setType(bool left){
    QString type;
    int n=0;
    foreach(type,l_types){
        std::cout<<n<<'.'<<type.toStdString()<<'\n';
        n++;
    }
    QString toSet;consoleInput(1).takeFirst();
    while(l_types.contains(toSet)){
        std::cout<<"Select type"<<'\n';
        toSet=consoleInput(1).takeFirst();
    }
    if(left)
        emit(leftTypeIsSet(toSet));
    else
        emit(rightTypeIsSet(toSet));
}

void ConsoleView::setOperation(){
    QString toSet;consoleInput(1).takeFirst();
    while(l_types.contains(toSet))
        toSet=consoleInput(1).takeFirst();
    emit(leftTypeIsSet(toSet));
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
