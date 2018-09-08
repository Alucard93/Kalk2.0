/**
 * @file genericfactory.h
 * @author Gianmarco Pettinato
 * @date 20/7/2018
 * @class Factory<T>
 * @brief this class is uses as base object to recall a Factory<t> getNewColor
*/
#include "../Color/color.h"
#ifndef GENERICFACTORY_H
#define GENERICFACTORY_H
class GenericFactory{
public:
    virtual Color* getNewColor() const =0;
    virtual Color* getNewColor(const Color* color) const =0;
    virtual ~GenericFactory() = default;
};
#endif // GENERICFACTORY_H
