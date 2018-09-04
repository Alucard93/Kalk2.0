#include "./colorfactory.h"

QMap<QString, GenericFactory*>* ColorFactory::allColorFactories=nullptr;

void ColorFactory::setUpColorFactory(){
    if(!ready())
    allColorFactories=new QMap<QString, GenericFactory*>();
}
void ColorFactory::destruct(){
    while(!allColorFactories->empty()){
        delete allColorFactories->first();
        allColorFactories->remove(getAllColorTypes()[0]);
    }
}

bool ColorFactory::ready(){
    return allColorFactories!=nullptr;
}

void ColorFactory::addColorFactory(const QString& name,GenericFactory& factory){
    allColorFactories->insert(name,&factory);
}

QVector<QString> ColorFactory::getAllColorTypes(){
    return allColorFactories->keys().toVector();
}

Color* ColorFactory::GetNewColor(QString& key) {
    return allColorFactories->value(key)->getNewColor();
}

Color* ColorFactory::Execution(Color* left, int operation, Color* right) {
    switch (operation) {
    case 0: return left->negate();
    case 1: return left->mix(right);

    }
    return nullptr;
}

Color* ColorFactory::Execution(Color* left, int operation, int right) {
    switch (operation) {
    case 2: return *left/(right);
    }
    return nullptr;
}

QVector<QString> ColorFactory::availableOperations() {
    QVector<QString> toReturn;
    for(int i=0; i<3; i++)
        toReturn.push_back(Color::allOpts[i][0]);
    return toReturn;

}
QVector<QString> ColorFactory::permittedOperations(QString& type) {
    Color* test = GetNewColor(type);
    return test->availableOperations();
}

QVector<QString> ColorFactory::typeByOperation(int operation) {
    QVector<QString> allColor=getAllColorTypes();
    QVector<QString> toReturn;
    toReturn.push_back("Select type");
    if(operation!=-1){
        for(int i=1;i<3&&(!Color::allOpts[operation][i].isEmpty());i++){
            if(Color::allOpts[operation][i]=="color")
                toReturn+=allColor;
            else
                toReturn.push_back(Color::allOpts[operation][i]);
        }
    }else{
        toReturn+=allColor;
    }
    return toReturn;
}
