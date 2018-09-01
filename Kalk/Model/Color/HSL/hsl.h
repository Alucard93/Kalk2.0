/**
 * @file hsl.h
 * @author Giuseppe Vito Bitetti
 * @date 20/7/2018
 * @class HSL
 * @brief this class uses as base the class CIExyz
 * and stores a color in HSL rappresentation
*/
#ifndef HSL_H
#define HSL_H

#include "../CIE_xyz/cie_xyz.h"

class HSL : public CIExyz{
public:
  HSL(double h=0, double s=0, double l=0);
  HSL(const Color* from);
  HSL(const HSL& from);
  QString getRappresentation() const;
  Color* negate() const;
  Color* mix(const Color* a)const;
  Color* getCIE(double h, double s, double l) const;
  QVector<double> getComponents() const;
  void setComponents(QVector<double> componets);
  int getNumberOfComponets() const;

private:
  double hue;
  double saturation;
  double lightness;
  double hsl_value(double t1, double t2, double h) const;
  constexpr static unsigned int upper_limit_sat_lig=360;
  constexpr static unsigned int lower_limit_sat_lig=0;
  constexpr static unsigned int upper_limit_hue=1;
  constexpr static unsigned int lower_limit_hue=0;
  constexpr static int componets = 3;
};
static Factory<HSL> HSLFactory;//Registers the class in ColorFactory
#endif // HSL_H
