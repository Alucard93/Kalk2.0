#include "cie_xyz.h"
/**
 * base constructor for CIExyz colour rappresentation
 * @brief CIExyz::CIExyz
 */
CIExyz::CIExyz(double _x,double _y, double _z){
    if(_x<lower_limit || _x>upper_limit || _y<lower_limit || _y>upper_limit)
        throw new IllegalColourException("value out of boundires");
    x=_x;
    y=_y;
    z=_z;
}

/**
 * base desctructor method
 * @brief CIExyz::~CIExyz
 */
CIExyz::~CIExyz(){
}


void CIExyz::show_rap(){
    std::cout<<"CIE xyz "<< x << " "<<y<<" "<<z;
}

Colour* CIExyz::negate() const{
    float nx=1-x;
    float ny=1-y;
    return  new CIExyz(nx,ny);
}

Colour* CIExyz::mix(Colour* c)const{
    CIExyz* b= nullptr_t();
    if(dynamic_cast<CIExyz*>(c))
        b=static_cast<CIExyz*>(c);
    else
        throw new IllegalColourException("illegal object");
    float nx= (b->x+this->x)/2;
    float ny= (b->y+this->y)/2;
    return new CIExyz(nx,ny);

}

CIExyz* CIExyz::getCIE() const{
    return new CIExyz(x,y);
}

int CIExyz::lower_limit=0;
int CIExyz::upper_limit=0;
