#ifndef COLOUR_H
#define COLOUR_H
#include <iostream>
#include <illegalcolourexception.h>
#include <array>
#include <QVector>
#include <QString>

class Colour{
public:
    virtual ~Colour();
    virtual QString getRappresentation()const =0;
    virtual Colour* getCIE()const =0;
    virtual Colour* negate()const =0;
    virtual Colour* mix(const Colour* c1)const =0;
    virtual QVector<double> getComponents() const =0;
};

#endif // COLOUR_H
