#ifndef COLOUR_H
#define COLOUR_H
#include <iostream>
#include <illegalcolourexception.h>
#include <QtGlobal>
using namespace std;
class Colour{
public:
    virtual ~Colour();
    virtual void show_rap()const =0;
    virtual Colour* getCIE()const =0;
    virtual Colour* negate()const =0;
    virtual Colour* mix(const Colour* c1)const =0;
protected:
    enum colour{
        not_valid
    };

};

#endif // COLOUR_H
