#include "../Color/color.h"
#ifndef GENERICFACTORY_H
#define GENERICFACTORY_H
class GenericFactory{
public:
    virtual Color* getNewColor() const =0;
};
#endif // GENERICFACTORY_H
