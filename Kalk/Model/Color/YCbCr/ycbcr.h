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
    YCbCr(double _y=0, double _cb=0, double _cr=0);
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
    constexpr static double min_cbcr= 16;
    Color* getRGB(double _y=0, double _u=0, double _v=0);
};
static Factory<YCbCr> YCbCrFactory;//Registers the class in ColorFactory
#endif // YCBCR_H
