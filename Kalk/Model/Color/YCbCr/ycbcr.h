#ifndef YCBCR_H
#define YCBCR_H

#include "../YUV/yuv.h"

class YCbCr : public YUV{
public:
    YCbCr(double _y=0, double _cb=0, double _cr=0);
    YCbCr(const Color* from);
    YCbCr(const YCbCr& from);
    QString getRappresentation() const;
    Color* negate() const;
    Color* mix(const Color* a)const;
    Color* getCIE(double y, double cb, double cr);
    Color* getYUV(double y, double cb, double cr);
    QVector<double> getComponents() const;
    int getNumberOfComponets() const;
    void setComponents(QVector<double> componets);
private:
    double cb;
    double cr;
    constexpr static int componets=3;
};

#endif // YCBCR_H
/*

*/
