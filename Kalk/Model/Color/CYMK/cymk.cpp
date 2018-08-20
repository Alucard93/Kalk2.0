#include "cymk.h"

CYMK::CYMK(unsigned int c , unsigned int y, unsigned int m, unsigned int k) : CIExyz(getCIE(c, y, m, k)){
    cyan=c;
    yellow=y;
    magenta=m;
    key_black=k;
}
CYMK::CYMK(const Color* from) : CIExyz(from){
    QVector<double> xyz=this->CIExyz::getComponents();
    double cp=1 -(3.063219*xyz[0] -1.393326*xyz[1] -0.475801*xyz[2]);
    double mp=1 -(-0.969245*xyz[0] +1.875968*xyz[1] +0.041555*xyz[2]);
    double yp=1 -(0.067872*xyz[0] -0.228833*xyz[1] +1.069251*xyz[2]);
    double kp=min({cp,mp,yp});
    double t=1-kp;
    if(t==0.0){
        cyan=0;
        yellow=0;
        magenta=0;
        key_black=0;
    }else{
        unsigned int c=static_cast<unsigned int>(((cp-kp)/t)*100);
        unsigned int y=static_cast<unsigned int>(((yp-kp)/t)*100);
        unsigned int m=static_cast<unsigned int>(((mp-kp)/t)*100);
        unsigned int k=static_cast<unsigned int>(kp);
        if((c>upper_limit_cymk || y>upper_limit_cymk || m>upper_limit_cymk || k>upper_limit_cymk) ||
           (c<lower_limit_cymk || y<lower_limit_cymk || m<lower_limit_cymk || k<lower_limit_cymk))
          throw IllegalColorException("il colore non rientra nei parametri");
        else{
            cyan=c;
            yellow=y;
            magenta=m;
            key_black=k;
        }
    }
}
CYMK::CYMK(const CYMK& from) : CIExyz(from){
    cyan=from.cyan;
    yellow=from.yellow;
    magenta=from.magenta;
    key_black=from.key_black;
}

QString CYMK::getRappresentation() const{
    return QString("CYMK");
}

Color* CYMK::negate() const{
    return new CYMK(this->CIExyz::negate());
}

Color* CYMK::mix(const Color* a)const{
    return new CYMK(this->mix(a));
}
Color* CYMK::getCIE(unsigned int c, unsigned int y, unsigned int m, unsigned int k) const{
    if((c>upper_limit_cymk || y>upper_limit_cymk || m>upper_limit_cymk || k>upper_limit_cymk) ||
       (c<lower_limit_cymk || y<lower_limit_cymk || m<lower_limit_cymk || k<lower_limit_cymk))
        throw IllegalColorException("il colore non rientra nei parametri");
    else{
        double tx=0.430574 * ((1-k/100)*(1-c/100)) + 0.341550 * ((1-k/100)*(1-m/100)) + 0.178325 * ((1-k/100)*(1-y/100));
        double ty=0.222015 * ((1-k/100)*(1-c/100)) + 0.706655 * ((1-k/100)*(1-m/100)) + 0.071330 * ((1-k/100)*(1-y/100));
        double tz=0.020183 * ((1-k/100)*(1-c/100)) + 0.129553 * ((1-k/100)*(1-m/100)) + 0.939180 * ((1-k/100)*(1-y/100));
        return new CIExyz(tx, ty, tz);
    }
}
QVector<double> CYMK::getComponents() const{
    QVector<double> to_return={static_cast<double>(cyan), static_cast<double>(yellow), static_cast<double>(magenta), static_cast<double>(key_black)};
    return to_return;
}
unsigned int CYMK::lower_limit_cymk=0;
unsigned int CYMK::upper_limit_cymk=100;
