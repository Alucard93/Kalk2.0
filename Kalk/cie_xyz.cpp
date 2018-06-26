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
 * @param _x
 * @param _y
 */
CIExyz::CIExyz(double _x,double _y){
    if(_x<lower_limit || _x>upper_limit || _y<lower_limit || _y>upper_limit)
        throw new IllegalColourException("value out of boundires");
    x=_x;
    y=_y;
    z=1-x-y;
}

CIExyz::~CIExyz(){
    delete static_cast<Colour*>(this);
}

void CIExyz::show_rap(){
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
    double nx= (b->x+this->x)/2;
    double ny= (b->y+this->y)/2;
    return new CIExyz(nx,ny);

}

Colour* CIExyz::getCIE() const{
    return new CIExyz(x,y);
}

int CIExyz::lower_limit=0;
int CIExyz::upper_limit=1;
