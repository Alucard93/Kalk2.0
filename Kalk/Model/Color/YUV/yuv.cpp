#include "yuv.h"

/**
 * @brief YUV::YUV Constructor for YUV color rappresentation from double precision numbers
 * @param _y
 * @param _u
 * @param _v
 */
YUV::YUV(double _y, double _u, double _v) : RGB(getCIE(_y, _u, _v)){
    y=_y;
    u=_u;
    v=_v;
}

/**
 * @brief YUV::YUV Constructor for YUV color rappresentation from Color pointer
 * @param from
 */
YUV::YUV(const Color* from) : RGB(from){
    QVector<double> xyz=CIExyz::getComponents();
    double ty= 0.354693074*xyz[0] + 0.026086962*xyz[1] + 0.121894614*xyz[2];
    double tu= -0.141115968408*xyz[0] - 0.12542071304*xyz[1] + 0.466099341912*xyz[2];
    double tv= 2.375377237102*xyz[0] - 1.244825167674*xyz[1] - 0.524179053478*xyz[2];
    if(tu>max_uv || tv>max_uv || tu<low_uv || tv<low_uv || ty>max_y ||ty<low_y){
        throw IllegalColorException("il colore non rientra nei parametri");
    }else{
        y=ty;
        u=tu;
        v=tv;
    }
}

/**
 * @brief YUV::YUV copy constructor
 * @param from
 */
YUV::YUV(const YUV& from) : RGB(from){
    y=from.y;
    u=from.u;
    v=from.v;
}

/**
 * @brief YUV::getRappresentation
 * @return QString that contains the meaning of the values contained in getComponents()
 */
QString YUV::getRappresentation() const{
    return QString("YUV");
}

/**
 * @brief YUV::negate
 * @return Color pointer with a new color with the complementar values
 */
Color* YUV::negate() const{
    return new YUV(RGB::negate());
}

/**
 * @brief YUV::mix
 * @param a
 * @return Color pointer with a new Object color mixed
 */
Color* YUV::mix(const Color* a)const{
    return new YUV(RGB::mix(a));
}

/**
 * @brief YUV::getRGB
 * @param _y
 * @param _u
 * @param _v
 * @return Color pointer with a clone of *this in the RGB format
 */
Color* YUV::getRGB(double _y, double _u, double _v){
    unsigned int r= static_cast<unsigned int>(_y + 1.140*_v);
    unsigned int g= static_cast<unsigned int>(_y - 0.395*_u - 0.581*_v);
    unsigned int b= static_cast<unsigned int>(_y + 2.032*_u);
    return new RGB(r,g,b);
}

/**
 * @brief YUV::getCIE
 * @param y
 * @param u
 * @param v
 * @return Color pointer with a clone of *this in the CIExyz format
 */
Color* YUV::getCIE(double y, double u, double v){
    unsigned int r= static_cast<unsigned int>(y + 1.140*v);
    unsigned int g= static_cast<unsigned int>(y - 0.395*u - 0.581*v);
    unsigned int b= static_cast<unsigned int>(y + 2.032*u);
    return RGB::getCIE(r, g, b);
}

/**
 * @brief YUV::getComponent
 * @return QVector<double> with the y, u, v component of the color in YUV
 */
QVector<double> YUV::getComponents() const{
    QVector<double> to_return={y,u,v};
    return to_return;
}

/**
 * @brief YUV::getNumberOfComponets
 * @return int componets number
 */
int YUV::getNumberOfComponets() const{
    return YUV::componets;
}

/**
 * @brief YUV::setComponents set the components inside the object
 * @param componets
 */
void YUV::setComponents(QVector<double> componets){
    y=componets[0];
    u=componets[1];
    v=componets[2];
    RGB::setComponents(YUV::getRGB(componets[0], componets[1], componets[2])->getComponents());
}

/**
 * @brief YUV::operator /
 * @param div
 * @return Color pointer with a new Object color
 */
Color* YUV::operator/(const int &div) const{
    return new YUV(RGB::operator/(div));
}
