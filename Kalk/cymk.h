#ifndef CYMK_H
#define CYMK_H
#include "cie_xyz.h"
#include "colour.h"
#include "illegalcolourexception.h"
class CYMK : public CIExyz{
public:
  CYMK(unsigned int c=0, unsigned int m=0, unsigned int y=0, unsigned int k=0);
  CYMK(Colour* from);
  CYMK(const CYMK& from);
  void getcymk();
private:
  unsigned int cyan;
  unsigned int magenta;
  unsigned int yellow;
  unsigned int key_black;
};

#endif // CYMK_H