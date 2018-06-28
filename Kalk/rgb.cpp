#include <rgb.h>

double RGB::CIE_RGB[3][3]={{3.2404542,-1.5371385,-0.4985314},
                           {-0.9692660,1.8760108,0.0415560},
                           {0.0556434,-0.2040259,1.0572252}};

double RGB::RGB_CIE[3][3]={{0.4124564, 0.3575761, 0.1804375},
                           {0.2126729, 0.7151522, 0.0721750},
                           {0.0193339, 0.1191920, 0.9503041}};
int RGB::upper_limit=255;
int RGB::lower_limit=0;

RGB::RGB(const Colour* t_c):CIExyz (t_c){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++)
            sRGB[i]+=static_cast<int>((CIE_RGB[i][j]*this->getComponent(j))*255);
    }
}

RGB::RGB(int t_r, int t_g, int t_b):CIExyz (RGB::getCIE()){
    if(t_r>upper_limit || t_r<lower_limit ||
       t_g>upper_limit || t_g<lower_limit ||
       t_b>upper_limit || t_b<lower_limit)
        throw new IllegalColourException("out of boundaries values");
    sRGB[0]=t_r;
    sRGB[1]=t_g;
    sRGB[2]=t_b;
}

RGB::RGB(const RGB* t_c){
    sRGB[0]=t_c->sRGB[0];
    sRGB[1]=t_c->sRGB[1];
    sRGB[2]=t_c->sRGB[2];
}

void RGB::show_rap() const{
    cout<<sRGB[0]<<" "<<sRGB[1]<<" "<<sRGB[2]<<" ";
}

Colour* RGB::negate()const{
    return new RGB (255-sRGB[0], 255-sRGB[1], 255-sRGB[2]);
}

Colour* RGB::mix(const Colour* t_c) const{
    const RGB* tomix = nullptr;
    if(dynamic_cast<const RGB*>(t_c))
        tomix= new RGB(static_cast<const RGB*>(t_c));
    else
       if(dynamic_cast<const CIExyz*>(t_c))
           tomix = new RGB(t_c);
       else
           throw new IllegalColourException("illegal colour definition");
    RGB* to_return = new RGB(((sRGB[0]+tomix->sRGB[0])/2),((sRGB[1]+tomix->sRGB[1])/2),((sRGB[2]+tomix->sRGB[2])/2));
    delete(tomix);
    return to_return;
}

Colour* RGB::getCIE() const{
    double cierap[3];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            double tomultiply = static_cast<double>(sRGB[j])/255;
            cierap[i]+=(RGB_CIE[i][j]*tomultiply);
        }
    }
    CIExyz* to_return=new CIExyz(cierap[0],cierap[1],cierap[2]);
    return to_return;
}

RGB* RGB::operator/(const int &div) const{
    return new RGB(sRGB[0]/div,sRGB[1]/div,sRGB[2]/div);
}
