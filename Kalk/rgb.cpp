#include <rgb.h>

static const double CIE_RGB[]={3.2404542,-1.5371385,-0.4985314,
                               -0.9692660,1.8760108,0.0415560,
                               0.0556434,-0.2040259,1.0572252};

static const double RGB_CIE[]={0.4124564, 0.3575761, 0.1804375,
                               0.2126729, 0.7151522, 0.0721750,
                               0.0193339,0.1191920,0.9503041};

RGB::RGB(const Colour* c):CIExyz (c){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++)
            sRGB[i]+=static_cast<int>(CIE_RGB[i][j]*this->get_component(j));
    }
}

RGB::RGB(int r, int g, int b):CIExyz (RGB::getCIE()){
    sRGB[0]=r;
    sRGB[1]=g;
    sRGB[2]=b;
}

RGB::RGB(const RGB* c){
    sRGB[0]=c->sRGB[0];
    sRGB[1]=c->sRGB[1];
    sRGB[2]=c->sRGB[2];
}

void RGB::show_rap() const{
    cout<<sRGB[0]<<" "<<sRGB[1]<<" "<<sRGB[2]<<" ";
}

Colour* RGB::negate()const{
    return new RGB (255-sRGB[0], 255-sRGB[1], 255-sRGB[2]);
}

Colour* RGB::mix(const Colour* c) const{
    const RGB* b = nullptr;
    if(dynamic_cast<const RGB*>(c))
        b= new RGB(static_cast<const RGB*>(c));
    else
       if(dynamic_cast<const CIExyz*>(c))
           b = new RGB(c);
       else
           throw new IllegalColourException("illegal colour definition");
    RGB* to_return = new RGB(((sRGB[0]+b->sRGB[0])/2),((sRGB[1]+b->sRGB[1])/2),((sRGB[2]+b->sRGB[2])/2));
    delete(b);
    return to_return;
}

Colour* RGB::getCIE() const{
    double cierap[3];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++)
            cierap[i]+=static_cast<int>(RGB_CIE[i][j]*sRGB[j]);
    }
    CIExyz* to_return=new CIExyz(cierap[0],cierap[1],cierap[2]);
    return to_return;
}

RGB* RGB::operator/(const int &div) const{
    return new RGB(sRGB[0]/div,sRGB[1]/div,sRGB[2]/div);
}
