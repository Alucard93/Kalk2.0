#include "./colorfactory.h"
#ifndef FACTORY_H
#define FACTORY_H
static ColorFactory inizializator;
template <class T> class Factory: public GenericFactory{
public:
    Factory(){
        if(!inizializator.constructor())
            throw new runtime_error("male");
    }
    Color* getNewColor() const{
        return new T;
    }
};
#endif // FACTORY_H
