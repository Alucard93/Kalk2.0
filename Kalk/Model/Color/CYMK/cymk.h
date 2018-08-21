#ifndef CYMK_H
#define CYMK_H

#include "../CIE_xyz/cie_xyz.h"

class CYMK : public CIExyz{
public:
  CYMK(unsigned int c=0, unsigned int y=0, unsigned int m=0, unsigned int k=0);
  CYMK(const Color* from);
  CYMK(const CYMK& from);
  QString getRappresentation() const;
  Color* negate() const;
  Color* mix(const Color* a)const;
  Color* getCIE(unsigned int c, unsigned int y, unsigned int m, unsigned int k) const;
  QVector<double> getComponents() const;
  int getNumberOfComponets() const;
  void setComponents(QVector<double> componets);

private:
  unsigned int cyan;
  unsigned int magenta;
  unsigned int yellow;
  unsigned int key_black;
  constexpr static unsigned int upper_limit_cymk=100;
  constexpr static unsigned int lower_limit_cymk=0;
  constexpr static const int componets=4;
};

#endif // CYMK_H
