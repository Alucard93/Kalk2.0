#include "ycbcr.h"

YCbCr::YCbCr(double _y, double _cb, double _cr) : RGB(getCIE(_y, _cb, _cr)){
    y=_y;
    cb=_cb;
    cr=_cr;
}
YCbCr::YCbCr(const Color* from) : RGB(from){
    RGB* temp= new RGB(from);
    QVector<double> rgb= temp->getComponents();
    double ty= 16  + 1/256* (65.738*rgb[0] + 129.057*rgb[1] + 25.064*rgb[2]);
    double tcb= 128 + 1/256* (-37.945*rgb[0] - 74.494*rgb[1] + 112.439*rgb[2]);
    double tcr= 128 + 1/256* (112.439*rgb[0] - 94.154*rgb[1] - 18.285*rgb[2]);
    if(tcb>max_cbcr || tcb>max_cbcr || tcr<min_cbcr || tcr<min_cbcr || ty>max_y ||ty<min_y){
        throw IllegalColorException("il colore non rientra nei parametri");
    }else{
        y=ty;
        cb=tcb;
        cr=tcr;
    }
}
YCbCr::YCbCr(const YCbCr& from) : RGB(from){
    y=from.y;
    cb=from.cb;
    cr=from.cr;
}
QString YCbCr::getRappresentation() const{
    return QString("YCbCr");
}
Color* YCbCr::negate() const{
    return new YCbCr(RGB::negate());
}
Color* YCbCr::mix(const Color* a)const{
    return new YCbCr(RGB::mix(a));
}
Color* YCbCr::getCIE(double y, double cb, double cr){
    unsigned int r= static_cast<unsigned int>((298.082*y + 408.583*cr) / 256 - 222.921);
    unsigned int g= static_cast<unsigned int>((298.082*y - 100.291*cb - 208.120*cr ) / 256 + 135.576);
    unsigned int b= static_cast<unsigned int>((298.082*y + 516.412*cb) / 256 - 276.836);
    return RGB::getCIE(r,g,b);
}
Color* YCbCr::getRGB(double y, double cb, double cr){
    unsigned int r= static_cast<unsigned int>((298.082*y + 408.583*cr) / 256 - 222.921);
    unsigned int g= static_cast<unsigned int>((298.082*y - 100.291*cb - 208.120*cr ) / 256 + 135.576);
    unsigned int b= static_cast<unsigned int>((298.082*y + 516.412*cb) / 256 - 276.836);
    return new RGB(r,g,b);
}
QVector<double> YCbCr::getComponents() const{
    QVector<double> to_return={y,cb,cr};
    return to_return;
}
int YCbCr::getNumberOfComponets() const{
    return YCbCr::componets;
}
void YCbCr::setComponents(QVector<double> componets){
    y=componets[0];
    cb=componets[1];
    cr=componets[2];
    RGB::setComponents(YCbCr::getRGB(componets[0], componets[1], componets[2])->getComponents());
}
Color* YCbCr::operator/(const int &div) const{
    return new YCbCr(RGB::operator/(div));
}
