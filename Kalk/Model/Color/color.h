#ifndef COLOR_H
#define COLOR_H
#include <iostream>
#include "../illegalcolorexception.h"
#include <array>
#include <QVector>

class Color{
public:

    //Class setup
    virtual int getNumberOfComponets() const =0;
    virtual void setComponents(QVector<double> componets) =0;

    //Possible operations
    virtual Color* getCIE()const =0;
    virtual Color* negate()const =0;
    virtual Color* mix(const Color* c1)const =0;
    virtual Color* operator/(const int &div) const =0;

    //Getting current status
    virtual QVector<double> getComponents() const =0;
    virtual QString getRappresentation()const =0;

};

#endif // COLOR_H
