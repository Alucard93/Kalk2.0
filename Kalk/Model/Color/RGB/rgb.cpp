#include "rgb.h"

double RGB::CIE_RGB[3][3]={{3.24045,-1.53713,-0.49853},
                           {-0.96926,1.87601,0.04155},
                           {0.05564,-0.20402,1.05722}};

double RGB::RGB_CIE[3][3]={{0.41245, 0.35757, 0.18043},
                           {0.21267, 0.71515, 0.07217},
                           {0.01933, 0.11919, 0.95030}};

const QVector<QString> RGB::implementedMethods={"negate","mix","divide"};
/**
 * @brief RGB::RGB
 * @param Color* t_c
 * Constructor for RGB that get a Color pointer
 * And inzialize parent objcet with a clone of CIExyz representation
 */
RGB::RGB(const Color* t_c):CIExyz(t_c)
{
    if(dynamic_cast<const RGB*>(t_c)){
        setComponents(t_c->getComponents());
    }
    else if (dynamic_cast<const CIExyz*>(t_c)){
        setComponents(CieXyz2rgb(dynamic_cast<const CIExyz*>(t_c)->getComponents()));
    }
}

/**
 * @brief RGB::RGB
 * @param RGB& t_c
 * Constructor that takes a RGB pointer and clones the object
 */
RGB::RGB(const RGB& t_c):CIExyz(t_c)
{
    sRGB[0]=t_c.sRGB[0];
    sRGB[1]=t_c.sRGB[1];
    sRGB[2]=t_c.sRGB[2];
}

/**
 * @brief RGB::RGB
 * @param RGB* t_c
 */
RGB::RGB(const RGB* t_c):CIExyz(t_c)
{
    sRGB[0]=t_c->sRGB[0];
    sRGB[1]=t_c->sRGB[1];
    sRGB[2]=t_c->sRGB[2];
}

/**
 * @brief RGB::RGB
 * @param int t_r
 * @param int t_g
 * @param int t_b
 * @throws IllegalColorException
 *
 * uses the local function getCIE(int t_r, int t_g, int t_b)
 * to inizialize the parent object
 * and set the local array values to rgb in input order
 */
RGB::RGB(int t_r, int t_g, int t_b):CIExyz(getCIE(t_r, t_g, t_b))
{
    if(t_r>upper_limit || t_r<lower_limit ||
       t_g>upper_limit || t_g<lower_limit ||
       t_b>upper_limit || t_b<lower_limit)
        throw IllegalColorException(getRepresentation().toStdString()+": valori non accettabili");
    sRGB[0]=t_r;
    sRGB[1]=t_g;
    sRGB[2]=t_b;
}

/**
 * @brief RGB::getrepresentation returns the meaning of the values contained in getComponents()
 * @return QString that contains name of the object
 */
QString RGB::getRepresentation() const
{
    return QString("RGB");
}

/**
 * @brief RGB::getNumberOfComponets
 * @return int
 */

int RGB::getNumberOfComponets() const
{
    return componets;
}
/**
 * @brief RGB::getLimits
 * @return RGB limits as QVector<QString>
 */
QVector<QString> RGB::getLimits() const{
    return {"Red",QString::number(lower_limit),QString::number(upper_limit),
            "Green",QString::number(lower_limit),QString::number(upper_limit),
            "Blue",QString::number(lower_limit),QString::number(upper_limit)};
}
/**
 * @brief RGB::setComponents set the components inside the object
 * @throws IllegalColorException
 * @param componets
 */

void RGB::setComponents(QVector<double> componets)
{
    CIExyz::setComponents(rgb2CieXyz(componets));
    if(componets[0]<lower_limit || componets[0]>upper_limit ||
       componets[1]<lower_limit || componets[1]>upper_limit ||
       componets[2]<lower_limit || componets[2]>upper_limit)
        throw IllegalColorException(getRepresentation().toStdString()+": valori non accettabili");
    sRGB[0]=static_cast<int>(componets[0]);
    sRGB[1]=static_cast<int>(componets[1]);
    sRGB[2]=static_cast<int>(componets[2]);

}

/**
 * @brief RGB::negate
 * @return return a new Color object with a new negated color as RGB
 */
Color* RGB::negate()const
{
    return new RGB (255-sRGB[0], 255-sRGB[1], 255-sRGB[2]);
}

/**
 * @brief RGB::mix
 * @param Color* t_c
 * @return a new Color object with the mixed Colors as RGB
 */
Color* RGB::mix(const Color* t_c) const
{
    RGB to_mix = new RGB(t_c);
    int r =((to_mix.sRGB[0]+sRGB[0])/2);
    int g =((to_mix.sRGB[1]+sRGB[1])/2);
    int b =((to_mix.sRGB[2]+sRGB[2])/2);
    delete &to_mix;
    return new RGB(r,g,b);
}

/**
 * @brief RGB::getCIE
 * @return a new Color object as CIExyz
 */

Color* RGB::getCIE() const
{
    return CIExyz::getCIE();
}

/**
 * @brief RGB::getCIE converts RGB value to CIExyz
 * @param int t_r
 * @param int t_g
 * @param int t_b
 * @return a new Color object as CIExyz*
 */
CIExyz* RGB::getCIE(int t_r, int t_g, int t_b) const
{
    QVector<double> rgbrepresentation={static_cast<double>(t_r),
            static_cast<double>(t_g),
            static_cast<double>(t_b)};
    QVector<double> cierap = rgb2CieXyz(rgbrepresentation);
    CIExyz* to_return=new CIExyz(cierap[0],cierap[1],cierap[2]);
    return to_return;
}

/**
 * @brief RGB::getComponents;
 * @return components in a QVector<double>
 */
QVector<double> RGB::getComponents() const
{
    QVector<double> to_return={static_cast<double>(sRGB[0]),
                               static_cast<double>(sRGB[1]),
                               static_cast<double>(sRGB[2])};
    return to_return;
}

/**
 * @brief RGB::operator / new RGB object with value divided
 * @param int div
 * @throws IllegalColorException
 * @return RGB
 */
Color* RGB::operator/(const int &div) const
{
    if(div<=0)
        throw IllegalColorException(getRepresentation().toStdString()+": non si può dividere per un numero minore di 1");
    return new RGB(sRGB[0]/div,sRGB[1]/div,sRGB[2]/div);
}

/**
 * @brief RGB::availableOperations returns all the operation that has been implemented
 * @return QVector<QString>
 */

QVector<QString> RGB::availableOperations() const
{
    return RGB::implementedMethods;
}

/**
 * @brief RGB::rgb2CieXyz
 * @param components
 * @return QVector<QString> with the matching values in CIExyz
 */

QVector<double> RGB::rgb2CieXyz(QVector<double> components) const
{
    QVector<double> cierap={0,0,0};
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            double tomultiply = components[j]/255;
            cierap[i]+=(RGB_CIE[i][j]*tomultiply);
        }
        cierap[i]=(static_cast<int>((cierap[i]*100000)))/100000.0;
    }
    return cierap;
}

/**
 * @brief RGB::CieXyz2rgb
 * @param components
 * @throws IllegalColorException
 * @return QVector<QString> with the matching values in RGB
 */

QVector<double> RGB::CieXyz2rgb(QVector<double> components)const{
    QVector<double> RGBrap={0,0,0};
    for(int i=0; i<3; i++)
    {
        double result = 0.0;
        for(int j=0; j<3; j++)
        {
            double tomultiply = components[j];
            result+=(static_cast<int>(CIE_RGB[i][j]*tomultiply*1000))/1000.0;
        }
        if(result<0)
            result = abs(result);
        if(result<=0.0031308){
            result = result*12.92;
        }else{
            result = ((pow(result,(1/2.4))*1.055)-0.055);
        }
        result = static_cast<int>(result*1000)/1000.0;
        RGBrap[i]=result*255;
        if(RGBrap[i]>255)//sRGB is a smaller color space
            throw IllegalColorException(getRepresentation().toStdString()+": il colore immesso non rientra nello spazio colore RGB");
    }
    return RGBrap;
}
