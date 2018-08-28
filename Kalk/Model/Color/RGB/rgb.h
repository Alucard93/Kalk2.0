/**
 * @file rgb.h
 * @author Gianmarco Pettinato
 * @date 20/7/2018
 * @class RGB
 * @brief this class uses the as base class CIExyz
 * and stores a color in RGB rappresentation
*/
#ifndef RGB_H
#define RGB_H
#include "../CIE_xyz/cie_xyz.h"
class RGB : public CIExyz{
public:
    //default constructor
    RGB(int r=0, int g=0, int b=0);
    //copy constructor
    RGB(const RGB& c);
    RGB(const RGB* c);

    RGB(const Color* c);
    ~RGB()=default;
    int getNumberOfComponets() const;
    void setComponents(QVector<double> componets);

    QString getRappresentation()const;
    Color* negate() const;
    Color* mix(const Color* c) const;
    QVector<QString> availableOperations() const;

    Color* getCIE() const;
    CIExyz* getCIE(int t_r, int t_g, int t_b) const;
    QVector<double>getComponents() const;
    Color* operator/(const int &div) const;

private:
    int sRGB[3];
    static double CIE_RGB[3][3]; //contains matrix to transforma CIExyz color rappresentation to sRGB
    static double RGB_CIE[3][3];//contains matrix to transforma sRGB color rappresentation to CIExyz
    constexpr static const int lower_limit = 0;
    constexpr static const int upper_limit = 255;
    constexpr static const int componets = 3;
    QVector<double> rgb2CieXyz(QVector<double> components) const;
    QVector<double> CieXyz2rgb (QVector<double> components) const;
    static const QVector<QString> implementedMethods;
};
static Factory<RGB> RGBFactory;//Registers the class in ColorFactory
#endif // RGB_H
