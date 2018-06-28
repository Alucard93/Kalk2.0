#ifndef COLOUR_H
#define COLOUR_H
#include <iostream>
#include "illegalcolourexception.h"
using namespace std;
class Colour{
public:
  Colour(int ll=0, int ul=0);
  virtual ~Colour();
  //virtual void show_rap()=0;
  //virtual void show_desc()=0;
  //virtual Colour* convert(Colour* from)=0;
  //virtual Colour* negate()const =0;
  //virtual Colour* mix(Colour* c1)const =0;

private:
  //string desc;
  int lower_limit;
  int upper_limit;
};

#endif // COLOUR_H
