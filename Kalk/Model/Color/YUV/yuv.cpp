#include "yuv.h"

YUV::YUV(double _y, double _u, double _v) : CIExyz(getCIE(_y, _u, _v)){
    y=_y;
    u=_u;
    v=_v;
}
YUV::YUV(const Color* from) : CIExyz(from){
    QVector<double> xyz=CIExyz::getComponents();
    double ty= 0.354693074*xyz[0] + 0.026086962*xyz[1] + 0.121894614*xyz[2];
    double tu= -0.141115968408*xyz[0] - 0.12542071304*xyz[1] + 0.466099341912*xyz[2];
    double tv= 2.375377237102*xyz[0] - 1.244825167674*xyz[1] - 0.524179053478*xyz[2];
    if(tu>max_uv || tv>max_uv || tu<low_uv || tv<low_uv){
        throw IllegalColorException("il colore non rientra nei parametri");
    }else{
        y=ty;
        u=tu;
        v=tv;
    }
}
YUV::YUV(const YUV& from) : CIExyz(from){
    y=from.y;
    u=from.u;
    v=from.v;
}
QString YUV::getRappresentation() const{
    return QString("YUV");
}
Color* YUV::negate() const{
    return new YUV(CIExyz::negate());
}
Color* YUV::mix(const Color* a)const{
    return new YUV(CIExyz::mix(a));
}
Color* YUV::getCIE(double y, double u, double v){
    double tx= 0.950449*y + 0.19844055*v + 0.1345707*u;
    double ty= y + 0.410566555*v + 0.051043882*u;
    double tz= 1.088916*y + 0.075270293*v + 0.021043882*u;
    return new CIExyz(tx, ty, tz);
}
QVector<double> YUV::getComponents() const{
    QVector<double> to_return={y,u,v};
    return to_return;
}
int YUV::getNumberOfComponets() const{
    return YUV::componets;
}
void YUV::setComponents(QVector<double> componets){
    QVector<double> tcie;
    tcie[0]= 0.950449*componets[0] + 0.19844055*componets[2] + 0.1345707*componets[1];
    tcie[1]= componets[0] + 0.410566555*componets[2] + 0.051043882*componets[1];
    tcie[2]= 1.088916*componets[0] + 0.075270293*componets[2] + 0.021043882*componets[1];
    CIExyz::setComponents(tcie);
    y=componets[0];
    u=componets[1];
    v=componets[2];
}
