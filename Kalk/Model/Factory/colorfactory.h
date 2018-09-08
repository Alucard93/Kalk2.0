/**
 * @file colorfactory.h
 * @author Gianmarco Pettinato
 * @date 20/7/2018
 * @class ColorFactory
 * @brief this class stores all Factories,
 * ColorFactory initializes a New Color object when required,
 * returns what kind of operation can be done with a specific color representation
 * and returns the result using the permitted operations
*/
#include <QMap>
#include "./genericfactory.h"
#include "../illegalcolorexception.h"
#include <typeinfo>
#ifndef COLORFACTORY_H
#define COLORFACTORY_H
class ColorFactory{
private:
    static QMap<QString, GenericFactory*>* allColorFactories;
public:
    static void setUpColorFactory();
    static void destruct();
    static bool ready();
    static void addColorFactory(const QString& name,GenericFactory& factory);
    static QVector<QString> getAllColorTypes();
    static Color* getNewColor(const QString& key);
    static Color* getNewColor(const QString& key, const Color* color);
    static Color* cloneColor(const Color* color);
    static Color* execution(const Color* left, int operation, const Color* right=nullptr);
    static Color* execution(const Color* left, const int& operation, const int right=1);
    static QVector<QString> availableOperations();
    static QVector<QString> permittedOperations(const QString& type);
    static QVector<QString> typeByOperation(int operation);
    static int getTypeSize();
};
#endif // COLORFACTORY_H

