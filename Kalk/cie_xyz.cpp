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

void CIExyz::show_rap()const{
    std::cout<<"CIE xyz "<< x << " "<<y<<" "<<z;
}

Colour* CIExyz::negate() const{
    double nx=1-x;
    double ny=1-y;
    return  new CIExyz(nx,ny);
}

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

Colour* CIExyz::getCIE() const{
    return new CIExyz(x,y);
}

double CIExyz::getComponent(int c) const{
    switch (c) {
    case 0: {double m_x =x;
            return m_x;}
    case 1: {double m_y =y;
            return m_y;}
    case 2: {double m_z =z;
            return m_z;}
    }
    return 0;
}

double CIExyz::getX() const{
    double t_x = x;
    return  t_x;
}

double CIExyz::getY() const{
    double t_y = y;
    return  t_y;
}

double CIExyz::getZ() const{
    double t_z = z;
    return  t_z;
}

double CIExyz::lower_limit_X=0;
double CIExyz::upper_limit_X=0.95047;
double CIExyz::lower_limit_Y=0;
double CIExyz::upper_limit_Y=1.00000;
double CIExyz::lower_limit_Z=0;
double CIExyz::upper_limit_Z=1.08883;
