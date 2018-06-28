#ifndef CIE_XYZ_H
#define CIE_XYZ_H
#include <colour.h>

class CIExyz : public Colour{
public:
    CIExyz(const Colour* c);
    CIExyz(double t_x=0, double t_y=0, double t_z=0);
    ~CIExyz();
    void show_rap() const;
    Colour* negate() const;
    Colour* mix(const Colour* c)const;
    Colour* getCIE() const;

protected:
    double getComponent(int c) const;
    double getX() const;
    double getY() const;
    double getZ() const;

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
