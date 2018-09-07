/**
 * @file ycbcr.h
 * @author Giuseppe Vito Bitetti
 * @date 20/7/2018
 * @class YCbCr
 * @brief this class uses as base the class RGB
 * and stores a color in YCbCr rappresentation
*/
#ifndef YCBCR_H
#define YCBCR_H

#include "../RGB/rgb.h"

class YCbCr : public RGB{
public:
    YCbCr(double _y=min_y, double _cb=min_cbcr, double _cr=min_cbcr);
    YCbCr(const Color* from);
    YCbCr(const YCbCr& from);

    int getNumberOfComponets() const;
    void setComponents(QVector<double> componets);

    QString getRappresentation() const;
    Color* negate() const;
    Color* mix(const Color* a)const;

    Color* getCIE(double y, double cb, double cr);
    QVector<double> getComponents() const;
    Color* operator/(const int &div) const;

private:
    double y;
    double cb;
    double cr;
    constexpr static int componets=3;
    constexpr static double max_y= 235;
    constexpr static double min_y= 16;
    constexpr static double max_cbcr= 240;
    constexpr static double min_cbcr= 128;
    static const double YCbCr_RGB[3][3];
    static const double RGB_YCbCr[3][3];
    static QVector<double> YCbCr2rgb(QVector<double> components);
    static QVector<double> rgb2YCbCr(QVector<double> components);
    Color* getRGB(double _y=0, double _u=0, double _v=0);
};
static Factory<YCbCr> YCbCrFactory;//Registers the class in ColorFactory
#endif // YCBCR_H
