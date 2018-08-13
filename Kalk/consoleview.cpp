#include <consoleview.h>

void ConsoleView::setAvTypes(QVector<QString> types){
    l_types=types;
}
void ConsoleView::setOperation(QVector<QString> operations){
    opts=operations;
}
void ConsoleView::printChoise(QString what){
    if(what=="type"){
        QString type;
        int i=0;
        foreach(type,l_types){
            std::cout<<i<<'.'<<type.toStdString()<<'\n';
            i++;
        }
    }else if(what=="op"){
        QString opt;
        int i=0;
        foreach(opt,opts){
            std::cout<<i<<'.'<<opt.toStdString()<<'\n';
            i++;
        }
    }
}
QVector<QString> ConsoleView::getvalues(){
    QVector<QString> toReturn;
    QString value;
    do{
        char c_value[64];
        std::cin>>c_value;
        value=c_value;
        toReturn.push_back(value);
    }while (!value.isEmpty());
    return toReturn;
}

void ConsoleView::printResult(QVector<QString> result){
    QString toPrint;
    foreach(toPrint,result){
        std::cout<<' '<<toPrint.toStdString();
    }
}
