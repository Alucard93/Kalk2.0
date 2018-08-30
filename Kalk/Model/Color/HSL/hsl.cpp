#include "hsl.h"

HSL::HSL(double h, double s, double l) : CIExyz(getCIE(h, s, l)){
    hue=h;
    saturation=s;
    lightness=l;
}
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
HSL::HSL(const HSL& from) : CIExyz(from){
    hue=from.hue;
    saturation=from.saturation;
    lightness=from.lightness;
}
QString HSL::getRappresentation() const{
    return QString("HSL");
}
Color* HSL::negate() const{
    return new HSL(this->CIExyz::negate());
}
Color* HSL::mix(const Color* a)const{
    return new HSL(this->mix(a));
}
Color* HSL::getCIE(double h, double s, double l) const{
    if((h>upper_limit_hue || s>upper_limit_sat_lig || l>upper_limit_sat_lig) ||
       (h<lower_limit_hue || s<lower_limit_sat_lig || l<lower_limit_sat_lig))
        throw IllegalColorException("il colore non rientra nei parametri");
    else{
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
        return new CIExyz(tx, ty, tz);
    }
}
QVector<double> HSL::getComponents() const{
    QVector<double> to_return={hue, saturation, lightness};
    return to_return;
}
void HSL::setComponents(QVector<double> componets){
    if((componets[0]>upper_limit_hue || componets[1]>upper_limit_sat_lig || componets[2]>upper_limit_sat_lig) ||
       (componets[0]<lower_limit_hue || componets[1]<lower_limit_sat_lig || componets[2]<lower_limit_sat_lig))
        throw IllegalColorException("il colore non rientra nei parametri");
    else{
        double t2;
        if(componets[2]<=0.5)
            t2=componets[2]+(componets[2]*componets[1]);
        else
            t2=(componets[2]+componets[1])-(componets[2]*componets[1]);
        double t1=(2*componets[2])-t2;
        QVector<double> tcie;
        if(qFuzzyCompare(componets[1], 0)){
            tcie[0]=0.430574 * componets[2] + 0.341550 * componets[2] + 0.178325 * componets[2];
            tcie[1]=0.222015 * componets[2] + 0.706655 * componets[2] + 0.071330 * componets[2];
            tcie[2]=0.020183 * componets[2] + 0.129553 * componets[2] + 0.939180 * componets[2];
        }else{
            tcie[0]=0.430574 * hsl_value(t1,t2,componets[0]+120) + 0.341550 * hsl_value(t1,t2,componets[0]) + 0.178325 * hsl_value(t1,t2,componets[0]-120);
            tcie[1]=0.222015 * hsl_value(t1,t2,componets[0]+120) + 0.706655 * hsl_value(t1,t2,componets[0]) + 0.071330 * hsl_value(t1,t2,componets[0]-120);
            tcie[2]=0.020183 * hsl_value(t1,t2,componets[0]+120) + 0.129553 * hsl_value(t1,t2,componets[0]) + 0.939180 * hsl_value(t1,t2,componets[0]-120);
        }
        hue=componets[0];
        saturation=componets[1];
        lightness=componets[3];
        CIExyz::setComponents(tcie);
    }
}
int HSL::getNumberOfComponets() const{
    return HSL::componets;
}
double HSL::hsl_value(double t1, double t2, double h) const{
    if(h>upper_limit_hue)
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
