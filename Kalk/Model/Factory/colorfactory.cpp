#include "./colorfactory.h"

QMap<QString, GenericFactory*>* ColorFactory::allColorFactories=nullptr;

/**
 * @brief ColorFactory::setUpColorFactory
 * Setups the data structure to be populated by addColorFactory
 */
void ColorFactory::setUpColorFactory(){
    if(!ready())
        allColorFactories=new QMap<QString, GenericFactory*>();
}
/**
 * @brief ColorFactory::destruct
 * deletes all data from allColorFactories;
 */
void ColorFactory::destruct(){
    QMap<QString, GenericFactory*>::Iterator it = allColorFactories->begin();
    while(it!=allColorFactories->end())
        it = allColorFactories->erase(it);
}

/**
 * @brief ColorFactory::ready
 * @return if the Data Structure is ready to be filled
 */
bool ColorFactory::ready(){
    return allColorFactories!=nullptr;
}
/**
 * @brief ColorFactory::addColorFactory
 * @param name
 * @param factory
 * adds an entry to allColorFactories
 */
void ColorFactory::addColorFactory(const QString& name,GenericFactory& factory){
    allColorFactories->insert(name,&factory);
}

/**
 * @brief ColorFactory::getAllColorTypes
 * @return returns all color types that are available
 */
QVector<QString> ColorFactory::getAllColorTypes(){
    return allColorFactories->keys().toVector();
}

/**
 * @brief ColorFactory::getNewColor
 * @param key
 * @return a new Color representation;
 * returns a new Color representation;
 */
Color* ColorFactory::getNewColor(const QString& key) {
    return allColorFactories->value(key)->getNewColor();
}

/**
 * @brief ColorFactory::getNewColor
 * @param key
 * @param color
 * @return a new Color representation
 */
Color* ColorFactory::getNewColor(const QString& key, const Color* color){
    return allColorFactories->value(key)->getNewColor(color);
}

/**
 * @brief ColorFactory::cloneColor
 * @param color
 * @return a clone of color
 * Clones color with deep copy;
 */
Color* ColorFactory::cloneColor(const Color* color){
    QString type=typeid(*color).name()+1;
    Color * toReturn = getNewColor(type);
    toReturn->setComponents(color->getComponents());
    return toReturn;
}

/**
 * @brief ColorFactory::execution
 * @param left
 * @param operation
 * @param right
 * @return the result o the operation
 */
Color* ColorFactory::execution(const Color* left, int operation, const Color* right) {
    switch (operation) {
    case 0: return left->negate();
    case 1: return left->mix(right);
    default: return nullptr;
    }
}

/**
 * @brief ColorFactory::execution
 * @param left
 * @param operation
 * @param right
 * @return the result o the operation
 */

Color* ColorFactory::execution(const Color* left, const int& operation, const int right) {
    switch (operation) {
    case 2: return *left/(right);
    }
    return nullptr;
}

/**
 * @brief ColorFactory::availableOperations
 * @return all the available operations
 */
QVector<QString> ColorFactory::availableOperations() {
    QVector<QString> toReturn;
    for(int i=0; i<3; i++)
        toReturn.push_back(Color::allOpts[i][0]);
    return toReturn;

}
/**
 * @brief ColorFactory::permittedOperations
 * @param type
 * @return all the permitted operations
 */
QVector<QString> ColorFactory::permittedOperations(const QString& type) {
    Color* test = getNewColor(type);
    QVector<QString> permittedOps = test->availableOperations();
    delete test;
    return permittedOps;
}

/**
 * @brief ColorFactory::typeByOperation
 * @param operation
 * @return all kind of color representation that can be used in a selected operation;
 */
QVector<QString> ColorFactory::typeByOperation(int operation) {
    QVector<QString> allColor=getAllColorTypes();
    QVector<QString> toReturn;
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
