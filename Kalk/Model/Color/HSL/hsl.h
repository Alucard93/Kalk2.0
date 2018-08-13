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
private:
  double hue;
  double saturation;
  double lightness;
  double hsl_value(double t1, double t2, double h) const;
  static unsigned int upper_limit_sat_lig;
  static unsigned int lower_limit_sat_lig;
  static unsigned int upper_limit_hue;
  static unsigned int lower_limit_hue;
};

#endif // HSL_H
