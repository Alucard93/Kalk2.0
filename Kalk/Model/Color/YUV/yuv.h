#ifndef YUV_H
#define YUV_H

#include "../CIE_xyz/cie_xyz.h"

class YUV : public CIExyz{
public:
  YUV(double _y=0, double _u=0, double _v=0);
  YUV(const Color* from);
  YUV(const YUV& from);
  QString getRappresentation() const;
  Color* negate() const;
  Color* mix(const Color* a)const;
  Color* getCIE(double y, double u, double v);
  QVector<double> getComponents() const;
  int getNumberOfComponets() const;
  void setComponents(QVector<double> componets);
private:
  double y;
  double u;
  double v;
  constexpr static double low_uv = -0.6;
  constexpr static double max_uv = 0.6;
  constexpr static int componets=3;
};

#endif // YUV_H
/*
//from yuv to ciexyz
X = 0.950449*Y' + 0.19844055*V' + 0.1345707*U'
Y = Y'+ 0.410566555*V' + 0.051043882*U'
Z = 1.088916*Y' + 0.075270293*V' + 0.021043882*U'

//form ciexyz to yuv
Y'= 0.354693074*X + 0.026086962*Y + 0.121894614*Z
U'= -0.141115968408*X - 0.12542071304*Y + 0.466099341912*Z
V'= 2.375377237102*X - 1.244825167674*Y - 0.524179053478*Z
*/
