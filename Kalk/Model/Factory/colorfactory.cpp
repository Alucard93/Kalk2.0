#include "./colorfactory.h"
QVector<QString> ColorFactory::getAllColorTypes(){
    /**map<QString,GenericFactory*>::iterator it = allFactories.begin();
    QVector<QString> toReturn;
    while(it!=allFactories.end())
        toReturn.push_back(it->first);
    return toReturn;*/
    return allColors;
}

Color* ColorFactory::GetNewColor(QString key) {
    return allFactories[0]->getNewColor();
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
    case 2: return left->operator/(right);
    }
    return nullptr;
}

QVector<QString> ColorFactory::availableOperations() {
    QVector<QString> toReturn;
    for(int i=0; i<3; i++)
        toReturn.push_back(Color::allOpts[i][0]);
    return toReturn;

}
QVector<QString> ColorFactory::permittedOperations(QString type) {
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
