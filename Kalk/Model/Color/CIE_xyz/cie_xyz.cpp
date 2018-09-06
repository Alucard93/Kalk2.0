#include "cie_xyz.h"
const QVector<QString> CIExyz::implementedMethods={"negate","mix"};

/**
 * @brief CIExyz::CIExyz Constructor for CIE xyz color rappresentation from double precision numbers
 * @param t_x
 * @param t_y
 * @param t_z
 */

CIExyz::CIExyz(double t_x,double t_y, double t_z)
{
    if(t_x<lower_limit_X || t_x>upper_limit_X ||
       t_y<lower_limit_Y || t_y>upper_limit_Y ||
       t_z<lower_limit_Z || t_z>upper_limit_Z)
        throw IllegalColorException("values out of boundaries");
    x=t_x;
    y=t_y;
    z=t_z;
}

/**
 * @brief CIExyz::CIExyz copy constructor
 * @param c
 */

CIExyz::CIExyz(const CIExyz& c)
{
    x=c.x;
    y=c.y;
    z=c.z;
}


/**
 * @brief CIExyz::CIExyz Constructor for CIE xyz color rappresentation from Color pointer
 * @param c
 */

CIExyz::CIExyz(const Color* c)
{
    CIExyz* b = nullptr;
    b=reinterpret_cast<CIExyz*>(c->getCIE());
    if(b==nullptr)
        throw IllegalColorException("illegal color definition");
    x=b->x;
    y=b->y;
    z=b->z;
}

/**
 * @brief CIExyz::getNumberOfComponets
 * @return int componets number
 */
int CIExyz::getNumberOfComponets() const
{
    return componets;
}

/**
 * @brief CIExyz::setComponents set the components inside the object
 * @param componets
 */

void CIExyz::setComponents(QVector<double> componets)
{
    if(componets[0]<lower_limit_X || componets[0]>upper_limit_X ||
       componets[1]<lower_limit_Y || componets[1]>upper_limit_Y ||
       componets[2]<lower_limit_Z || componets[2]>upper_limit_Z)
        throw IllegalColorException("values out of boundaries");
    x=componets[0];
    y=componets[1];
    z=componets[2];
}
QVector<QString> CIExyz::getLimits() const{
    return {QString::number(lower_limit_X),QString::number(upper_limit_X),
            QString::number(lower_limit_Y),QString::number(upper_limit_Y),
            QString::number(lower_limit_Z),QString::number(upper_limit_Z)};
}

/**
 * @brief CIExyz::getRappresentation
 * @return QString that contains the meaning of the values contained in getComponents()
 */
QString CIExyz::getRappresentation()const
{
    return QString("XYZ");
}

/**
 * @brief CIExyz::negate
 * @return Color pointer with a new color with the complementar values
 */
Color* CIExyz::negate() const
{
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
Color* CIExyz::mix(const Color* c)const
{
    CIExyz b = new CIExyz(c);
    double m_x= (b.x+this->x)/2;
    double m_y= (b.y+this->y)/2;
    double m_z= (b.z+this->z)/2;
    return new CIExyz(m_x,m_y,m_z);

}
/**
 * @brief CIExyz::getCIE
 * @return Color pointer with a clone of *this
 */
Color* CIExyz::getCIE() const
{
    return new CIExyz(*this);
}

/**
 * @brief CIExyz::getComponent
 * @return QVector<double> with the x y z component of the color in CIE XYZ
 */

QVector<double> CIExyz::getComponents() const{
    QVector<double> to_return={x,y,z};
    return to_return;
}

/**
 * @brief CIExyz::availableOperations
 * @return all the operation that has been implemented
 */
QVector<QString> CIExyz::availableOperations() const{
    return implementedMethods;
}

/**
 * @brief CIExyz::operator /
 * @throws IllegalColorException("operation not available");
 */

Color* CIExyz::operator/(const int &div) const{
    throw IllegalColorException("operation not available");
}


