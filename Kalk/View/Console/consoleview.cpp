#include "consoleview.h"
#include <iostream>
#include <QApplication>

QVector<QString> ConsoleView::menu={"Nuovo(default)","Cronologia","Chiudi"};

/**
 * @brief ConsoleView::ConsoleView
 * @param console
 */
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
void ConsoleView::setLeftFields(const int& fields, const QVector<QString>& limits){
    l_size=fields;
    l_limits = limits;
}
/**
 * @brief ConsoleView::setRightFields
 * @param fields
 * sets up r_size variable
 */
void ConsoleView::setRightFields(const int& fields,const QVector<QString>& limits){
    r_size=fields;
    r_limits=limits;
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
    result_size=fields;
}

/**
 * @brief ConsoleView::error prints error message in terminal
 * @param error_message
 */
void ConsoleView::error(const QString& error_message){
    std::cout<<error_message.toStdString()<<'\n';
}

/**
 * @brief ConsoleView::show
 * inizialize the view inside the terminal
 */

void ConsoleView::show(){
    bool exit=false;
    while(!exit){
        showMenu();
        QString choice = consoleInput(1)[0];
        switch (choice.toInt()) {
        case 1:
            emit getHistory();
            break;
        case 2:
            exit = true;
            break;
        default:
            newOperation();
            break;
        }
    }
}

/**
 * @brief ConsoleView::newOperation
 * Shows the interface for new operation
 */


void ConsoleView::newOperation()
{
    showChoices(l_types);

    emit leftTypeIsSet(l_types[consoleInput(1).first().toInt()]);
    std::cout<<'\n'<<"richiede "<<l_size<<" elementi"<<'\n';
    emit leftValuesAreSet(consoleInput(l_size,l_limits));
    showChoices(permittedOpts);
    emit operationIsSet(permittedOpts[consoleInput(1).first().toInt()]);
    if(r_types.last()!="non disponibile"){
        showChoices(r_types);
        emit rightTypeIsSet(r_types[consoleInput(1).first().toInt()]);
        std::cout<<'\n'<<"richiede "<<r_size<<" elementi"<<'\n';
        emit rightValuesAreSet(consoleInput(r_size,r_limits));
    }
    std::cout<<'\n'<<"Risultato"<<'\n';
    emit getResult();
    showString(local_result);
    std::cout<<"Vuoi cambiare il tipo di ritorno?(s/[n])"<<'\n';
    char response;
    std::cin>>response;
    if(response=='s'){
        showChoices(l_types);
        emit resultTypeIsSet(l_types[consoleInput(1).first().toInt()]);
        showString(local_result);
    }

}

/**
 * @brief ConsoleView::consoleInput
 * @param n
 * @return user input in QVector<QString>
 * used to read input from user
 */
QVector<QString> ConsoleView::consoleInput(int n, const QVector<QString>& limits){
    bool limitsInt= (n==limits.size()/3);
    QVector<QString> toReturn;
    while(toReturn.size()<n){
        if(limits[0]!="no" && limitsInt)
            std::cout<<limits[toReturn.size()*3].toStdString()
                    <<": min "
                   <<limits[toReturn.size()*3+1].toStdString()
                  << " max "
                  <<limits[toReturn.size()*3+2].toStdString()<<'\n';
        char c_string[64];
        std::cin>>c_string;
        toReturn.push_back(c_string);
    }
    return  toReturn;
}

/**
 * @brief ConsoleView::showChoices shows the choices
 * @param s_vector
 */
void ConsoleView::showChoices(const QVector<QString>& s_vector){
    std::cout<<'\n'<<"Selezione una voce"<<'\n';
    QString line;
    int number = 0;
    foreach(line,s_vector){
        std::cout<<number<<'.'<<line.toStdString()<<'\n';
        number++;
    }
    std::cout<<'\n';
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
    std::cout<<'\n';
}
/**
 * @brief ConsoleView::setHistory
 * @param history
 * shows history on terminal
 */

void ConsoleView::setHistory(const QVector<QVector<QString>>& history){
    QVector<QString> lines;
    int op=history.size();
    foreach(lines, history){
        std::cout<<"Operazione n."<<op<<"\n";
        showString(lines);
    }

}
/**
 * @brief ConsoleView::showMenu
 * shows basic operation the menù in the terminal
 */

void ConsoleView::showMenu(){
    showChoices(menu);
}

/**
 * @brief ConsoleView::resetType
 * @param drop
 * @param type
 */
void ConsoleView::resetType(QString drop, QString type){
    std::cout<<drop.toStdString()<<" è stato resettato a "<<type.toStdString()<<'\n';
}
