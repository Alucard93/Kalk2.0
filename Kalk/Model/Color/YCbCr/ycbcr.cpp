#include "ycbcr.h"

/**
 * @brief YCbCr::YCbC Constructor for YCbCr color rappresentation from double precision numbers
 * @param _y
 * @param _cb
 * @param _cr
 */
YCbCr::YCbCr(double _y, double _cb, double _cr) : RGB(getCIE(_y, _cb, _cr)){
    y=_y;
    cb=_cb;
    cr=_cr;
}

/**
 * @brief YCbCr::YCbCr Constructor for YCbCr color rappresentation from Color pointer
 * @param from
 */
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

/**
 * @brief YCbCr::YCbCr copy constructor
 * @param from
 */
YCbCr::YCbCr(const YCbCr& from) : RGB(from){
    y=from.y;
    cb=from.cb;
    cr=from.cr;
}

/**
 * @brief YCbCr::getRappresentation
 * @return QString that contains the meaning of the values contained in getComponents()
 */
QString YCbCr::getRappresentation() const{
    return QString("YCbCr");
}

/**
 * @brief YCbCr::negate
 * @return Color pointer with a new color with the complementar values
 */
Color* YCbCr::negate() const{
    return new YCbCr(RGB::negate());
}

/**
 * @brief YCbCr::mix
 * @param a
 * @return Color pointer with a new Object color mixed
 */
Color* YCbCr::mix(const Color* a)const{
    return new YCbCr(RGB::mix(a));
}

/**
 * @brief YCbCr::getCIE
 * @param y
 * @param cb
 * @param cr
 * @return Color pointer with a clone of *this in the CIExyz format
 */
Color* YCbCr::getCIE(double y, double cb, double cr){
    unsigned int r= static_cast<unsigned int>((298.082*y + 408.583*cr) / 256 - 222.921);
    unsigned int g= static_cast<unsigned int>((298.082*y - 100.291*cb - 208.120*cr ) / 256 + 135.576);
    unsigned int b= static_cast<unsigned int>((298.082*y + 516.412*cb) / 256 - 276.836);
    return RGB::getCIE(r,g,b);
}

/**
 * @brief YCbCr::getRGB
 * @param y
 * @param cb
 * @param cr
 * @return Color pointer with a clone of *this in the RGB format
 */
Color* YCbCr::getRGB(double y, double cb, double cr){
    unsigned int r= static_cast<unsigned int>((298.082*y + 408.583*cr) / 256 - 222.921);
    unsigned int g= static_cast<unsigned int>((298.082*y - 100.291*cb - 208.120*cr ) / 256 + 135.576);
    unsigned int b= static_cast<unsigned int>((298.082*y + 516.412*cb) / 256 - 276.836);
    return new RGB(r,g,b);
}

/**
 * @brief YCbCr::getComponent
 * @return QVector<double> with the y, cb, cr component of the color in YCbCr
 */
QVector<double> YCbCr::getComponents() const{
    QVector<double> to_return={y,cb,cr};
    return to_return;
}

/**
 * @brief YCbCr::getNumberOfComponets
 * @return int componets number
 */
int YCbCr::getNumberOfComponets() const{
    return YCbCr::componets;
}

/**
 * @brief YCbCr::setComponents set the components inside the object
 * @param componets
 */
void YCbCr::setComponents(QVector<double> componets){
    y=componets[0];
    cb=componets[1];
    cr=componets[2];
    RGB::setComponents(YCbCr::getRGB(componets[0], componets[1], componets[2])->getComponents());
}

/**
 * @brief YCbCr::operator /
 * @param div
 * @return Color pointer with a new Object color
 */
Color* YCbCr::operator/(const int &div) const{
    return new YCbCr(RGB::operator/(div));
}
