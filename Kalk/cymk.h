#ifndef CYMK_H
#define CYMK_H

#include "cie_xyz.h"

class CYMK : public CIExyz{
public:
  CYMK(unsigned int c=0, unsigned int y=0, unsigned int m=0, unsigned int k=0);
  CYMK(const Colour* from);
  CYMK(const CYMK& from);
  ~CYMK();
  QString getRappresentation() const;
  Colour* negate() const;
  Colour* mix(const Colour* a)const;
  Colour* getCIE(unsigned int c, unsigned int y, unsigned int m, unsigned int k) const;
  QVector<double> getComponents() const;
private:
  unsigned int cyan;
  unsigned int magenta;
  unsigned int yellow;
  unsigned int key_black;
  static unsigned int upper_limit_cymk;
  static unsigned int lower_limit_cymk;
};

#endif // CYMK_H
