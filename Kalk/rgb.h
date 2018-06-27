#ifndef RGB_H
#define RGB_H
#include <cie_xyz.h>
#include <QtMath>

class RGB : public CIExyz{
public:
    RGB(int r=0, int g=0, int b=0);
    RGB(const Colour* c);
    RGB(const RGB* c);
    void show_rap() const;
    Colour* negate() const;
    Colour* mix(const Colour* c) const;
    Colour* getCIE() const;
    RGB* operator/(const int &div) const;

private:
    int sRGB[3];
    static const double CIE_RGB[3][3]; //contains matrix to transforma CIE colour rappresentation to sRGB
    static const double RGB_CIE[3][3];
};

#endif // RGB_H
