#include "hsl.h"

/**
 * @brief HSL::HSL Constructor for HSL color representation from double precision numbers
 * @param h
 * @param s
 * @param l
 */
HSL::HSL(double h, double s, double l) : CIExyz(getCIE(h, s, l)){
    hue=h;
    saturation=s;
    lightness=l;
}

/**
 * @brief HSL::HSL Constructor for HSL color representation from Color pointer
 * @param from
 */
HSL::HSL(const Color* from) : CIExyz(from){
    QVector<double> xyz=this->CIExyz::getComponents();
    double t1=3.063219*xyz[0] -1.393326*xyz[1] -0.475801*xyz[2];
    double t2=-0.969245*xyz[0] +1.875968*xyz[1] +0.041555*xyz[2];
    double t3=0.067872*xyz[0] -0.228833*xyz[1] +1.069251*xyz[2];
    double max_v=max({t1, t2, t3});
    double min_v=min({t1, t2, t3});
    lightness=(max_v+min_v)/2;
    if(qFuzzyCompare(max_v, min_v)){
        saturation=0;
        hue=0;
    }else{
        double delta_v=max_v-min_v;
        if(lightness<=0.5)
            saturation=delta_v/(max_v+min_v);
        else
            saturation=delta_v/(2-max_v-min_v);
        double t1c=(max_v-t1)/delta_v;
        double t2c=(max_v-t2)/delta_v;
        double t3c=(max_v-t3)/delta_v;
        if(qFuzzyCompare(t1, max_v))
            hue=t3c-t2c;
        else if(qFuzzyCompare(t2, max_v))
            hue=2+t1c-t3c;
        else
            hue=4+t2c-t1c;
        hue=hue*60;
        if(hue>=upper_limit_hue)
            hue-=upper_limit_hue;
        if(hue<lower_limit_hue)
            hue+=upper_limit_hue;
    }
}

/**
 * @brief HSL::HSL copy constructor
 * @param from
 */
HSL::HSL(const HSL& from) : CIExyz(from){
    hue=from.hue;
    saturation=from.saturation;
    lightness=from.lightness;
}

/**
 * @brief HSL::getrepresentation
 * @return QString that contains name of the object
 */
QString HSL::getRepresentation() const{
    return QString("HSL");
}

/**
 * @brief HSL::negate
 * @return Color pointer with a new color with the negated values
 */
Color* HSL::negate() const{
    double h=hue+upper_limit_hue/2;
    if(h > upper_limit_hue)
       h-=upper_limit_hue;
    return new HSL(h, saturation, lightness);
}

/**
 * @brief HSL::mix
 * @param a
 * @return Color pointer with a new color mixed as HSL
 */
Color* HSL::mix(const Color* a)const{
    return new HSL(CIExyz::mix(a));
}

/**
 * @brief HSL::getCIE
 * @param h
 * @param s
 * @param l
 * @throws IllegalColorException
 * @return Color pointer with a clone of *this in the CIExyz format
 */
Color* HSL::getCIE(double h, double s, double l) const{
    if((h>upper_limit_hue || s>upper_limit_sat_lig || l>upper_limit_sat_lig) ||
            (h<lower_limit_hue || s<lower_limit_sat_lig || l<lower_limit_sat_lig))
        throw IllegalColorException(getRepresentation().toStdString()+": valori non accettabili");

    double t2;
    if(l<=0.5)
        t2=l+(l*s);
    else
        t2=(l+s)-(l*s);
    double t1=(2*l)-t2;
    double tx;
    double ty;
    double tz;
    if(qFuzzyCompare(s, 0)){
        tx=0.430574 * l + 0.341550 * l + 0.178325 * l;
        ty=0.222015 * l + 0.706655 * l + 0.071330 * l;
        tz=0.020183 * l + 0.129553 * l + 0.939180 * l;
    }else{
        tx=0.430574 * hsl_value(t1,t2,h+120) + 0.341550 * hsl_value(t1,t2,h) + 0.178325 * hsl_value(t1,t2,h-120);
        ty=0.222015 * hsl_value(t1,t2,h+120) + 0.706655 * hsl_value(t1,t2,h) + 0.071330 * hsl_value(t1,t2,h-120);
        tz=0.020183 * hsl_value(t1,t2,h+120) + 0.129553 * hsl_value(t1,t2,h) + 0.939180 * hsl_value(t1,t2,h-120);
    }
    tx=static_cast<int>(tx*10000)/10000.0;
    ty=static_cast<int>(ty*10000)/10000.0;
    tz=static_cast<int>(ty*10000)/10000.0;
    return new CIExyz(tx, ty, tz);
}

/**
 * @brief HSL::getComponent
 * @return QVector<double> with the hue, saturation, lightness component of the color in HSL
 */
QVector<double> HSL::getComponents() const{
    QVector<double> to_return={hue, saturation, lightness};
    return to_return;
}

/**
 * @brief HSL::setComponents set the components inside the object
 * @throws IllegalColorException
 * @param componets
 */
void HSL::setComponents(QVector<double> componets){
    if((componets[0]>upper_limit_hue || componets[1]>upper_limit_sat_lig || componets[2]>upper_limit_sat_lig) ||
            (componets[0]<lower_limit_hue || componets[1]<lower_limit_sat_lig || componets[2]<lower_limit_sat_lig))
        throw IllegalColorException(getRepresentation().toStdString()+": valori non accettabili");

    double t2;
    if(componets[2]<=0.5)
        t2=componets[2]+(componets[2]*componets[1]);
    else
        t2=(componets[2]+componets[1])-(componets[2]*componets[1]);
    double t1=(2*componets[2])-t2;
    QVector<double> tcie;
    if(qFuzzyCompare(componets[1], 0)){
        tcie.append(0.430574 * componets[2] + 0.341550 * componets[2] + 0.178325 * componets[2]);
        tcie.append(0.222015 * componets[2] + 0.706655 * componets[2] + 0.071330 * componets[2]);
        tcie.append(0.020183 * componets[2] + 0.129553 * componets[2] + 0.939180 * componets[2]);
    }else{
        tcie.append(0.430574 * hsl_value(t1,t2,componets[0]+120) + 0.341550 * hsl_value(t1,t2,componets[0]) + 0.178325 * hsl_value(t1,t2,componets[0]-120));
        tcie.append(0.222015 * hsl_value(t1,t2,componets[0]+120) + 0.706655 * hsl_value(t1,t2,componets[0]) + 0.071330 * hsl_value(t1,t2,componets[0]-120));
        tcie.append(0.020183 * hsl_value(t1,t2,componets[0]+120) + 0.129553 * hsl_value(t1,t2,componets[0]) + 0.939180 * hsl_value(t1,t2,componets[0]-120));
    }
    hue=componets[0];
    saturation=componets[1];
    lightness=componets[2];
    tcie[0]=(static_cast<int>(tcie[0]*1000))/1000.0;
    tcie[1]=(static_cast<int>(tcie[1]*1000))/1000.0;
    tcie[2]=(static_cast<int>(tcie[2]*1000))/1000.0;
    CIExyz::setComponents(tcie);
}

/**
 * @brief HSL::getNumberOfComponets
 * @return int componets number
 */
int HSL::getNumberOfComponets() const{
    return HSL::componets;
}

/**
 * @brief HSL::hsl_value
 * @param t1
 * @param t2
 * @param t3
 * @return double that rappresent the hue in module
 */
double HSL::hsl_value(double t1, double t2, double h) const{
    if(h>=upper_limit_hue)
        h-=upper_limit_hue;
    if(h<lower_limit_hue)
        h+=upper_limit_hue;
    if(h<60)
        return t1+(t2-t1)*(h/60);
    else if(h<180)
        return t2;
    else if(h<240)
        return t1+(t2-t1)*((240-h)/60);
    else
        return t1;
}

/**
 * @brief HSL::getLimits
 * @return limits of HSL as QVector<QString>
 */
QVector<QString> HSL::getLimits() const{
    return {"Hue",QString::number(lower_limit_hue),QString::number(upper_limit_hue),
                "Saturation",QString::number(lower_limit_sat_lig),QString::number(upper_limit_sat_lig),
                "Lightness",QString::number(lower_limit_sat_lig),QString::number(upper_limit_sat_lig)};
}
