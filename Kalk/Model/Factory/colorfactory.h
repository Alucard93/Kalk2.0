#include <QMap>
#include "./genericfactory.h"
#include "../illegalcolorexception.h"
#ifndef COLORFACTORY_H
#define COLORFACTORY_H
class ColorFactory{
private:
    static QMap<QString, GenericFactory*>* allColorFactories;
public:
    ColorFactory(){
        if(allColorFactories==nullptr)
        allColorFactories=new QMap<QString, GenericFactory*>();
    }
    bool constructor();
    static bool addColorFactory(QString name,GenericFactory& factory);
    static QVector<QString> getAllColorTypes();
    static Color* GetNewColor(QString& key);
    static Color* Execution(Color* left, int operation, Color* right=nullptr);
    static Color* Execution(Color* left, int operation, int right=1);
    static QVector<QString> availableOperations();
    static QVector<QString> permittedOperations(QString& type);
    static QVector<QString> typeByOperation(int operation);
    static int getTypeSize();
};
#endif // COLORFACTORY_H

