#include "../Color/color.h"
#include <map>
#include <memory>
#include <iostream>
#ifndef GENERICFACTORY_H
#define GENERICFACTORY_H
class GenericFactory{
public:
    virtual Color* getNewColor()=0;
};

#endif // GENERICFACTORY_H

#ifndef TEMPLATE_FACTORY
#define TEMPLATE_FACTORY

template <class T> class Factory: public GenericFactory{
public:
    Color* getNewColor(){
        return new T;
    }
};
#endif //TEMPLATE_FACTORY

#ifndef COLORFACTORY_H
#define COLORFACTORY_H
class ColorFactory{
private:
    QVector<QString> allColors;
    QVector<GenericFactory *> allFactories;
public:
    template <class T> bool addColorFactory(){
        //allFactories.insert(typeid(Z).name(),new Factory<Z>);
        //allFactories[typeid(Z).name()]=new Factory<Z>;
        allColors.push_back(typeid(T).name());
        allFactories.push_back(new Factory<T>);
        return true;
    }
    QVector<QString> getAllColorTypes();
    Color* GetNewColor(QString key);
    Color* Execution(Color* left, int operation, Color* right=nullptr);
    Color* Execution(Color* left, int operation, int right=1);
    QVector<QString> availableOperations();
    QVector<QString> permittedOperations(QString type);
    QVector<QString> typeByOperation(int operation);
    int getTypeSize();
};

static std::unique_ptr<ColorFactory> global_Factory(new ColorFactory);
#endif // COLORFACTORY_H


