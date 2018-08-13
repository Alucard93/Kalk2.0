#include "cie_xyz.h"

/**
 * Constructor for CIE xyz color rappresentation from Color pointer
 * @brief CIExyz::CIExyz
 * @param c
 */

CIExyz::CIExyz(const Color* c){
    CIExyz* b = nullptr;
    b=static_cast<CIExyz*>(c->getCIE());
    if(b==nullptr)
        throw new IllegalColorException("illegal color definition");
    x=b->x;
    y=b->y;
    z=b->z;
}
/**
 * Constructor for CIE xyz color rappresentation from double precision numbers
 * @brief CIExyz::CIExyz
 * @param t_x
 * @param t_y
 * @param t_z
 */
CIExyz::CIExyz(double t_x,double t_y, double t_z){
    if(t_x<lower_limit_X || t_x>upper_limit_X ||
       t_y<lower_limit_Y || t_y>upper_limit_Y ||
       t_z<lower_limit_Z || t_z>upper_limit_Z)
        throw new IllegalColorException("value out of boundires");
    x=t_x;
    y=t_y;
    z=t_z;
}

CIExyz::~CIExyz(){
    delete static_cast<Color*>(this);
}
int CIExyz::getNumberOfComponets() const{
    return componets;
}

void CIExyz::setComponents(QVector<double> componets){
    if(componets[0]<lower_limit_X || componets[0]>upper_limit_X ||
       componets[1]<lower_limit_Y || componets[1]>upper_limit_Y ||
       componets[2]<lower_limit_Z || componets[2]>upper_limit_Z)
        throw new IllegalColorException("value out of boundires");
    x=componets[0];
    y=componets[1];
    z=componets[3];
}
/**
 * @brief CIExyz::getRappresentation
 * @return QString that contains the meaning of the values contained in getComponents()
 */
QString CIExyz::getRappresentation()const{
    return QString("XYZ");
}

/**
 * @brief CIExyz::negate
 * @return Color pointer with a new color with the complementar values
 */
Color* CIExyz::negate() const{
    double nx=upper_limit_X-x;
    double ny=upper_limit_Y-y;
    double nz=upper_limit_Z-z;
    return  new CIExyz(nx,ny,nz);
}
/**
 * @brief CIExyz::mix
 * @param c
 * @return Color pointer with a new Object color mixed
 */
Color* CIExyz::mix(const Color* c)const{
    CIExyz* b=nullptr;
    b=static_cast<CIExyz*>(c->getCIE());
    if(b==nullptr)
        throw new IllegalColorException("illegal object");
    double m_x= (b->x+this->x)/2;
    double m_y= (b->y+this->y)/2;
    double m_z= (b->z+this->z)/2;
    return new CIExyz(m_x,m_y,m_z);

}
/**
 * @brief CIExyz::getCIE
 * @return Color pointer with a clone of *this
 */
Color* CIExyz::getCIE() const{
    return new CIExyz(x,y, z);
}

/**
 * @brief CIExyz::getComponent
 * @return QVector<double> with the x y z component of the color in CIE XYZ
 */

QVector<double> CIExyz::getComponents() const{
    QVector<double> to_return={x,y,z};
    return to_return;
}

Color* CIExyz::operator/(const int &div) const{
    throw new IllegalColorException("operation not available");
}

double CIExyz::lower_limit_X=0;
double CIExyz::upper_limit_X=0.95047;
double CIExyz::lower_limit_Y=0;
double CIExyz::upper_limit_Y=1.00000;
double CIExyz::lower_limit_Z=0;
double CIExyz::upper_limit_Z=1.08883;
int CIExyz::componets=3;
