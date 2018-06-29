#ifndef CIE_XYZ_H
#define CIE_XYZ_H
#include <colour.h>

class CIExyz : public Colour{
public:
    CIExyz(const Colour* c);
    CIExyz(double _x=0, double _y=0, double _z=0);
    ~CIExyz();
    void show_rap() const;
    Colour* negate() const;
    Colour* mix(const Colour* c)const;
    Colour* getCIE() const;

protected:
    double get_component(int c) const;
    double get_x() const;
    double get_y() const;
    double get_z() const;

private:
  double x;
  double y;
  double z;
  static int upper_limit;
  static int lower_limit;
};

#endif // CIE_XYZ_H
