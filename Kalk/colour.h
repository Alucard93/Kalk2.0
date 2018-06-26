#ifndef COLOUR_H
#define COLOUR_H
#include <iostream>
#include <illegalcolourexception.h>
using namespace std;
class Colour{
public:
    virtual ~Colour();
    virtual void show_rap()=0;
    virtual Colour* getCIE()const =0;
    virtual Colour* negate()const =0;
    virtual Colour* mix(const Colour* c1)const =0;
};

#endif // COLOUR_H
