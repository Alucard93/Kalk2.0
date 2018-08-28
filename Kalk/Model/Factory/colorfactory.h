/**
 * @file colorfactory.h
 * @author Gianmarco Pettinato
 * @date 20/7/2018
 * @class ColorFactory
 * @brief this class stores all Factories,
 * initializes a New Color object when required,
 * returns what kind of operation can be done with a specific color rappresentation
 * and returs the result using the permitted operations
*/
#include <QMap>
#include "./genericfactory.h"
#include "../illegalcolorexception.h"
#ifndef COLORFACTORY_H
#define COLORFACTORY_H
class ColorFactory{
private:
    static QMap<QString, GenericFactory*>* allColorFactories;
public:
    static void setUpColorFactory();
    static bool ready();
    static void addColorFactory(const QString& name,GenericFactory& factory);
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

