#include "cymk.h"

CYMK::CYMK(unsigned int c , unsigned int y, unsigned int m, unsigned int k) : CIExyz(getCIE(c, y, m, k)){
  if(c>100 || m>100 || c>100 || y>100 || k>100)
    throw IllegalColourException("il colore non rienttra nei parametri");
  else{
    cyan=c;
    yellow=y;
    magenta=m;
    key_black=k;
  }
}
CYMK::CYMK(const Colour* from) : CIExyz(from){
    double cp=1-(3.063219*X -1.393326*Y -0.475801*Z);
    double mp=1-(-0.969245*X +1.875968*Y +0.041555*Z);
    double yp=1-(0.067872*X -0.228833*Y +1.069251*Z);
    double kp=fmin(cp,fmin(mp,yp));
    double t=1-kp;
    if(t=0){
        cyan=0;
        yellow=0;
        magenta=0;
    }else{
        cyan=static_cast<unsigned int>(((cp-kp)/t)*100);
        yellow=static_cast<unsigned int>(((yp-kp)/t)*100);
        magenta=static_cast<unsigned int>(((mp-kp)/t)*100);
    }
    key_black=static_cast<unsigned int>(kp);
}

CYMK::CYMK(const CYMK& from) : CIExyz(from){
    cyan=from.cyan;
    yellow=from.yellow;
    magenta=from.magenta;
    key_black=from.key_black;
}

Colour* CYMK::getCIE(unsigned int c, unsigned int y, unsigned int m, unsigned int k) const{
    if(c>100 || m>100 || c>100 || y>100 || k>100)
        throw IllegalColourException("il colore non rienttra nei parametri");
    else{
        double tx=0.430574 * ((1-k/100)*(1-c/100)) + 0.341550 * ((1-k/100)*(1-m/100)) + 0.178325 * ((1-k/100)*(1-y/100));
        double ty=0.222015 * ((1-k/100)*(1-c/100)) + 0.706655 * ((1-k/100)*(1-m/100)) + 0.071330 * ((1-k/100)*(1-y/100));
        double tz=0.020183 * ((1-k/100)*(1-c/100)) + 0.129553 * ((1-k/100)*(1-m/100)) + 0.939180 * ((1-k/100)*(1-y/100));
        return new CIExyz(tx, ty, tz);
    }
}

void CYMK::getcymk() const{
    std::cout<<cyan<<'\n'<<magenta<<'\n'<<yellow<<'\n'<<key_black<<'\n';
}
