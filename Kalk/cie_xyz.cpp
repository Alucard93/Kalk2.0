#include <cie_xyz.h>

/**
 * Constructor for CIE xyz colour rappresentation from Colour pointer
 * @brief CIExyz::CIExyz
 * @param c
 */

CIExyz::CIExyz(const Colour* c){
    CIExyz* b = nullptr;
    b=static_cast<CIExyz*>(c->getCIE());
    if(b==nullptr)
        throw new IllegalColourException("illegal colour definition");
    x=b->x;
    y=b->y;
    z=b->z;
}
/**
 * Constructor for CIE xyz colour rappresentation from double precision numbers
 * @brief CIExyz::CIExyz
 * @param t_x
 * @param t_y
 * @param t_z
 */
CIExyz::CIExyz(double t_x,double t_y, double t_z){
    if(t_x<lower_limit_X || t_x>upper_limit_X ||
       t_y<lower_limit_Y || t_y>upper_limit_Y ||
       t_z<lower_limit_Z || t_z>upper_limit_Z)
        throw new IllegalColourException("value out of boundires");
    x=t_x;
    y=t_y;
    z=t_z;
}

CIExyz::~CIExyz(){
    delete static_cast<Colour*>(this);
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
 * @return Colour pointer with a new colour with the complementar values
 */
Colour* CIExyz::negate() const{
    double nx=upper_limit_X-x;
    double ny=upper_limit_Y-y;
    double nz=upper_limit_Z-z;
    return  new CIExyz(nx,ny,nz);
}
/**
 * @brief CIExyz::mix
 * @param c
 * @return Colour pointer with a new Object colour mixed
 */
Colour* CIExyz::mix(const Colour* c)const{
    CIExyz* b=nullptr;
    b=static_cast<CIExyz*>(c->getCIE());
    if(b==nullptr)
        throw new IllegalColourException("illegal object");
    double m_x= (b->x+this->x)/2;
    double m_y= (b->y+this->y)/2;
    double m_z= (b->z+this->z)/2;
    return new CIExyz(m_x,m_y,m_z);

}
/**
 * @brief CIExyz::getCIE
 * @return Colour pointer with a clone of *this
 */
Colour* CIExyz::getCIE() const{
    return new CIExyz(x,y, z);
}

/**
 * @brief CIExyz::getComponent
 * @return QVector<double> with the x y z component of the colour in CIE XYZ
 */

QVector<double> CIExyz::getComponents() const{
    QVector<double> to_return={x,y,z};
    return to_return;
}

double CIExyz::lower_limit_X=0;
double CIExyz::upper_limit_X=0.95047;
double CIExyz::lower_limit_Y=0;
double CIExyz::upper_limit_Y=1.00000;
double CIExyz::lower_limit_Z=0;
double CIExyz::upper_limit_Z=1.08883;
