#include <rgb.h>

double RGB::CIE_RGB[3][3]={{3.2404542,-1.5371385,-0.4985314},
                           {-0.9692660,1.8760108,0.0415560},
                           {0.0556434,-0.2040259,1.0572252}};

double RGB::RGB_CIE[3][3]={{0.4124564, 0.3575761, 0.1804375},
                           {0.2126729, 0.7151522, 0.0721750},
                           {0.0193339, 0.1191920, 0.9503041}};
int RGB::upper_limit=255;
int RGB::lower_limit=0;

/**
 * @brief RGB::RGB
 * @param Color* t_c
 * Constructor for RGB that get a Color pointer
 * And inzialize parent objcet with a clone of CIExyz rappresentation
 */
RGB::RGB(const Color* t_c):CIExyz(t_c){
    QVector<double> CIE_DATA=getComponents();
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++)
            sRGB[i]+=((CIE_RGB[i][j]*CIE_DATA[j])*255);
    }
}
/**
 * @brief RGB::RGB
 * @param int t_r
 * @param int t_g
 * @param int t_b
 * uses the local function getCIE(int t_r, int t_g, int t_b)
 * to inizialize the parent object
 * and set the local array values to rgb in input order
 */
RGB::RGB(int t_r, int t_g, int t_b):CIExyz(getCIE(t_r, t_g, t_b)){
    if(t_r>upper_limit || t_r<lower_limit ||
       t_g>upper_limit || t_g<lower_limit ||
       t_b>upper_limit || t_b<lower_limit)
        throw new IllegalColorException("out of boundaries values");
    sRGB[0]=t_r;
    sRGB[1]=t_g;
    sRGB[2]=t_b;
}

/**
 * @brief RGB::RGB
 * @param RGB* t_c
 * Constructor that takes a RGB pointer and clones the object
 */
RGB::RGB(const RGB* t_c):CIExyz(static_cast<const Color*>(t_c)){
    sRGB[0]=t_c->sRGB[0];
    sRGB[1]=t_c->sRGB[1];
    sRGB[2]=t_c->sRGB[2];
}

/**
 * @brief RGB::getRappresentation
 * @return QString that contains the meaning of the values contained in getComponents()
 */
QString RGB::getRappresentation() const{
    return QString("RGB");
}

/**
 * @brief RGB::negate
 * @return return a new Color object with a new complementary color
 */
Color* RGB::negate()const{
    return new RGB (255-sRGB[0], 255-sRGB[1], 255-sRGB[2]);
}

/**
 * @brief RGB::mix
 * @param Color* t_c
 * @return a new Color object with the mixed Colors
 */
Color* RGB::mix(const Color* t_c) const{
    const RGB* tomix = nullptr;
    if(dynamic_cast<const RGB*>(t_c))
        tomix= new RGB(static_cast<const RGB*>(t_c));
    else
       if(dynamic_cast<const CIExyz*>(t_c))
           tomix = new RGB(t_c);
       else
           throw new IllegalColorException("illegal color definition");
    RGB* to_return = new RGB(((sRGB[0]+tomix->sRGB[0])/2),((sRGB[1]+tomix->sRGB[1])/2),((sRGB[2]+tomix->sRGB[2])/2));
    delete(tomix);
    return to_return;
}

/**
 * @brief RGB::getCIE
 * @param int t_r
 * @param int t_g
 * @param int t_b
 * @return Color Pointer with only CIE rappresentation
 */
Color* RGB::getCIE(int t_r, int t_g, int t_b) const{
    double cierap[3];
    int o_sRGB[3]={t_r,t_g,t_b};
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            double tomultiply = static_cast<double>(o_sRGB[j])/255;
            cierap[i]+=(RGB_CIE[i][j]*tomultiply);
        }
    }
    CIExyz* to_return=new CIExyz(cierap[0],cierap[1],cierap[2]);
    return to_return;
}

Color* RGB::getColorFromVector(QVector<double> comp) const{
    int r,g,b;
    r = static_cast<int>(comp[0]);
    g = static_cast<int>(comp[1]);
    b = static_cast<int>(comp[2]);
    return new RGB(r,g,b);
}

/**
 * @brief RGB::getComponent
 * @return QVector<double> with component in RGB class;
 */
QVector<double> RGB::getComponents() const{
    QVector<double> to_return={static_cast<double>(sRGB[0]),
                               static_cast<double>(sRGB[1]),
                               static_cast<double>(sRGB[2])};
    return to_return;
}

/**
 * @brief RGB::operator /
 * @param int div
 * @return new RGB object with value divided
 */
RGB* RGB::operator/(const int &div) const{
    return new RGB(sRGB[0]/div,sRGB[1]/div,sRGB[2]/div);
}
