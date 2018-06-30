#ifndef RGB_H
#define RGB_H
#include <cie_xyz.h>
#include <colour.h>
class RGB : public CIExyz{
public:
    RGB(int r=0, int g=0, int b=0);
    RGB(const Colour* c);
    RGB(const RGB* c);
    QString getRappresentation()const;
    Colour* negate() const;
    Colour* mix(const Colour* c) const;
    Colour* getCIE() const;
    Colour* getCIE(int t_r, int t_g, int t_b) const;
    QVector<double>getComponent() const;
    RGB* operator/(const int &div) const;

private:
    int sRGB[3];
    static double CIE_RGB[3][3]; //contains matrix to transforma CIE colour rappresentation to sRGB
    static double RGB_CIE[3][3];
    static int lower_limit;
    static int upper_limit;
};

#endif // RGB_H
