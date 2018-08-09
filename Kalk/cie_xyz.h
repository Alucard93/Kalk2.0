#ifndef CIE_XYZ_H
#define CIE_XYZ_H
#include "color.h"

class CIExyz : public Color{
public:
    CIExyz(const Color* c);
    CIExyz(double t_x=0, double t_y=0, double t_z=0);
    ~CIExyz();
    QString getRappresentation() const;
    Color* negate() const;
    Color* mix(const Color* c)const;
    Color* getCIE() const;
    QVector<double>getComponents() const;

private:
  double x;
  double y;
  double z;
  static double upper_limit_X;
  static double lower_limit_X;
  static double upper_limit_Y;
  static double lower_limit_Y;
  static double upper_limit_Z;
  static double lower_limit_Z;
};

#endif // CIE_XYZ_H
