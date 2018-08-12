#ifndef COLOR_H
#define COLOR_H
#include <iostream>
#include <illegalcolorexception.h>
#include <array>
#include <QVector>

class Color{
public:
    virtual ~Color();
    virtual QString getRappresentation()const =0;
    virtual Color* getCIE()const =0;
    virtual Color* negate()const =0;
    virtual Color* mix(const Color* c1)const =0;
    virtual Color* operator/(const int &div) const =0;
    virtual QVector<double> getComponents() const =0;

};

#endif // COLOR_H
