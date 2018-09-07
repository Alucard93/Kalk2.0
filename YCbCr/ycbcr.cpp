#include "ycbcr.h"

const double YCbCr::YCbCr_RGB[3][3]={{1.1643836,0,1.5960268},
                                     {1.1643836,-0.39176229,-0.81296765},
                                     {1.1643836,2.0172321,0}};

const double YCbCr::RGB_YCbCr[3][3]={{0.25678824,0.50412941,0.09790588},
                                     {-0.1482229,-0.29099279,0.43921569},
                                     {0.43921569,-0.36778831,-0.07142737}};
/**
 * @brief YCbCr::YCbC Constructor for YCbCr color rappresentation from double precision numbers
 * @param _y
 * @param _cb
 * @param _cr
 */
YCbCr::YCbCr(double _y, double _cb, double _cr) : RGB(getRGB(_y, _cb, _cr)){
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
    double ty= 16  + 1/255* (65.738*rgb[0] + 129.057*rgb[1] + 25.064*rgb[2]);
    double tcb= 128 + 1/255* (-37.945*rgb[0] - 74.494*rgb[1] + 112.439*rgb[2]);
    double tcr= 128 + 1/255* (112.439*rgb[0] - 94.154*rgb[1] - 18.285*rgb[2]);
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
    QVector<double> toSet = YCbCr2rgb({y,cb,cr});
    return new RGB(static_cast<int>(toSet[0]),static_cast<int>(toSet[1]),static_cast<int>(toSet[2]));
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

QVector<double> YCbCr::YCbCr2rgb(QVector<double> components)
{
    QVector<double> RGB={0,0,0};
    double tomultiply[3]={components[0]-16,components[1]-128,components[2]-128};
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            RGB[i]+=(YCbCr_RGB[i][j]*tomultiply[j]);
        }

    }
    return RGB;
}

QVector<double> YCbCr::rgb2YCbCr(QVector<double> components)
{
    QVector<double> ycbcr={0,0,0};
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            ycbcr[i]+=(RGB_YCbCr[i][j]*components[j]);
        }

    }
    ycbcr[0]+=16;
    ycbcr[1]+=128;
    ycbcr[2]+=128;
    return ycbcr;
}
