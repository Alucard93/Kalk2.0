#include "ycbcr.h"

YCbCr::YCbCr(double _y, double _cb, double _cr) : YUV(getYUV(_y, _cb, _cr)){
    cb=_cb;
    cr=_cr;
}
YCbCr::YCbCr(const Color* from){

}
YCbCr::YCbCr(const YCbCr& from) : YUV(from){
    cb=from.cb;
    cr=from.cr;
}
QString YCbCr::getRappresentation() const{
    return QString("YCbCr");
}
Color* YCbCr::negate() const{
    return new YCbCr(YUV::negate());
}
Color* YCbCr::mix(const Color* a)const{
    return new YCbCr(YUV::mix(a));
}
Color* YCbCr::getCIE(double y, double cb, double cr){

}
Color* YCbCr::getYUV(double y, double cb, double cr){

}
QVector<double> YCbCr::getComponents() const{
    QVector<double> to_return={YUV::getComponents()[0],cb,cr};
    return to_return;
}
int YCbCr::getNumberOfComponets() const{
    return YCbCr::componets;
}
void YCbCr::setComponents(QVector<double> componets){

}
