/**
 * @file yuv.h
 * @author Giuseppe Vito Bitetti
 * @date 20/7/2018
 * @class YUV
 * @brief this class uses as base the class RGB
 * and stores a color in YUV rappresentation
*/
#ifndef YUV_H
#define YUV_H

#include "../RGB/rgb.h"

class YUV : public RGB{
public:
    YUV(double _y=0, double _u=0, double _v=0);
    YUV(const Color* from);
    YUV(const YUV& from);
    QString getRappresentation() const;
    Color* negate() const;
    Color* mix(const Color* a)const;
    Color* getCIE(double y, double u, double v);
    QVector<double> getComponents() const;
    int getNumberOfComponets() const;
    void setComponents(QVector<double> componets);
    Color* operator/(const int &div) const;
private:
    double y;
    double u;
    double v;
    constexpr static double low_y = 0.0;
    constexpr static double max_y = 1.0;
    constexpr static double low_uv = -0.6;
    constexpr static double max_uv = 0.6;
    constexpr static int componets=3;
    Color* getRGB(double _y=0, double _u=0, double _v=0);
};

static Factory<YUV> YUVFactory;//Registers the class in ColorFactory
#endif // YUV_H
