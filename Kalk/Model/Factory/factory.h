/**
 * @file Factory.h
 * @author Gianmarco Pettinato
 * @date 20/7/2018
 * @class Factory<T>
 * @brief this class extends GenericFactory and implements getNewColor() and getNewColor(const Color* color)
 * inizializes the map allColorFactories in ColorFactory
 * and makes available to ColorFactory a constructor for the new
 * color requested
*/

#include "./colorfactory.h"
#ifndef FACTORY_H
#define FACTORY_H
#include <typeinfo>
template <class T> class Factory: public GenericFactory{
public:
    Factory(){
        if(!ColorFactory::ready())
            ColorFactory::setUpColorFactory();
        ColorFactory::addColorFactory(typeid(T).name()+1,*this);
    }
    ~Factory()=default;
    Color* getNewColor() const{
        return new T;
    }
    Color* getNewColor(const Color* color) const{
        return new T(color);
    }
};
#endif // FACTORY_H
