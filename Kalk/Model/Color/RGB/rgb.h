/**
 * @file rgb.h
 * @author Gianmarco Pettinato
 * @date 20/7/2018
 * @class RGB
 * @brief this class uses the as base class CIExyz
 * RGB stores a color in RGB representation
*/
#include <math.h>
#include "../CIE_xyz/cie_xyz.h"
#ifndef RGB_H
#define RGB_H
class RGB : public CIExyz{
public:
    //default constructor
    RGB(int r=0, int g=0, int b=0);
    //copy constructor
    RGB(const RGB& c);
    RGB(const RGB* c);
    RGB(const Color* c);

    ~RGB()=default;

    Color* getCIE() const;

    void setComponents(QVector<double> componets);
    QString getRepresentation()const;

    Color* negate() const;
    Color* mix(const Color* c) const;
    Color* operator/(const int &div) const;

    QVector<QString> availableOperations() const;
    QVector<double>getComponents() const;
    int getNumberOfComponets() const;
    QVector<QString> getLimits() const;

    CIExyz* getCIE(int t_r, int t_g, int t_b) const;
private:
    int sRGB[3];
    static double CIE_RGB[3][3]; //contains matrix to transforma CIExyz color representation to sRGB
    static double RGB_CIE[3][3];//contains matrix to transforma sRGB color representation to CIExyz
    constexpr static const int lower_limit = 0;
    constexpr static const int upper_limit = 255;
    constexpr static const int componets = 3;
    QVector<double> rgb2CieXyz(QVector<double> components) const;
    QVector<double> CieXyz2rgb (QVector<double> components) const;
    static const QVector<QString> implementedMethods;
};
static Factory<RGB> RGBFactory;//Registers the class in ColorFactory
#endif // RGB_H
