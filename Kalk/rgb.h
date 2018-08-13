#ifndef RGB_H
#define RGB_H
#include <cie_xyz.h>
#include <color.h>
class RGB : public CIExyz{
public:
    RGB(int r=0, int g=0, int b=0);
    RGB(const Color* c);
    RGB(const RGB* c);
    QString getRappresentation()const;
    Color* negate() const;
    Color* mix(const Color* c) const;
    //Color* getCIE() const;
    Color* getCIE(int t_r, int t_g, int t_b) const;
    Color* getColorFromVector(QVector<double> comp) const;
    QVector<double>getComponents() const;
    Color* operator/(const int &div) const;

private:
    int sRGB[3];
    static double CIE_RGB[3][3]; //contains matrix to transforma CIE color rappresentation to sRGB
    static double RGB_CIE[3][3];
    static int lower_limit;
    static int upper_limit;
};

#endif // RGB_H
