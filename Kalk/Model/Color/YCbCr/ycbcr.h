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

#endif // YCBCR_H
/*
Y' = 16  + 1/256 * (   65.738  * R'd +  129.057  * G'd +  25.064  * B'd)
 Cb = 128 + 1/256 * ( - 37.945  * R'd -   74.494  * G'd + 112.439  * B'd)
 Cr = 128 + 1/256 * (  112.439  * R'd -   94.154  * G'd -  18.285  * B'd)

 R'd = ( 298.082 * Y'                + 408.583 * Cr ) / 256 - 222.921
 G'd = ( 298.082 * Y' - 100.291 * Cb - 208.120 * Cr ) / 256 + 135.576
 B'd = ( 298.082 * Y' + 516.412 * Cb                ) / 256 - 276.836
*/
