#include "cymk.h"

/**
 * @brief CYMK::CYMK Constructor for CYMK color rappresentation from unsigned int numbers
 * @param c
 * @param y
 * @param m
 * @param k
 */
CYMK::CYMK(unsigned int c , unsigned int y, unsigned int m, unsigned int k) : CIExyz(getCIE(c, y, m, k)){
    cyan=c;
    yellow=y;
    magenta=m;
    key_black=k;
}

/**
 * @brief CYMK::CYMK Constructor for CYMK color rappresentation from Color pointer
 * @param from
 */
CYMK::CYMK(const Color* from) : CIExyz(from){
    QVector<double> xyz=CIExyz::getComponents();
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
        if((c>upper_limit_cymk || y>upper_limit_cymk || m>upper_limit_cymk || k>upper_limit_cymk))
            throw IllegalColorException("il colore non rientra nei parametri");
        else{
            cyan=c;
            yellow=y;
            magenta=m;
            key_black=k;
        }
    }
}

/**
 * @brief CYMK::CYMK copy constructor
 * @param from
 */
CYMK::CYMK(const CYMK& from) : CIExyz(from){
    cyan=from.cyan;
    yellow=from.yellow;
    magenta=from.magenta;
    key_black=from.key_black;
}

/**
 * @brief CYMK::getRappresentation
 * @return QString that contains the meaning of the values contained in getComponents()
 */
QString CYMK::getRappresentation() const{
    return QString("CYMK");
}

/**
 * @brief CYMK::negate
 * @return Color pointer with a new color with the complementar values
 */
Color* CYMK::negate() const{
    return new CYMK(CIExyz::negate());
}

/**
 * @brief CYMK::mix
 * @param a
 * @return Color pointer with a new Object color mixed
 */
Color* CYMK::mix(const Color* a)const{
    return new CYMK(this->CIExyz::mix(a));
}

/**
 * @brief CYMK::getCIE
 * @param c
 * @param y
 * @param m
 * @param k
 * @return Color pointer with a clone of *this in the CIExyz format
 */
Color* CYMK::getCIE(unsigned int c, unsigned int y, unsigned int m, unsigned int k) const{
    if((c>upper_limit_cymk || y>upper_limit_cymk || m>upper_limit_cymk || k>upper_limit_cymk))
        throw IllegalColorException("il colore non rientra nei parametri");
    else{
        //double tx=0.430574 * ((1-k/100)*(1-c/100)) + 0.341550 * ((1-k/100)*(1-m/100)) + 0.178325 * ((1-k/100)*(1-y/100));
        //double ty=0.222015 * ((1-k/100)*(1-c/100)) + 0.706655 * ((1-k/100)*(1-m/100)) + 0.071330 * ((1-k/100)*(1-y/100));
        //double tz=0.020183 * ((1-k/100)*(1-c/100)) + 0.129553 * ((1-k/100)*(1-m/100)) + 0.939180 * ((1-k/100)*(1-y/100));

        double tx=0.41245 * ((1-k/100)*(1-c/100)) + 0.35757 * ((1-k/100)*(1-m/100)) + 0.18043 * ((1-k/100)*(1-y/100));
        double ty=0.21267 * ((1-k/100)*(1-c/100)) + 0.71515 * ((1-k/100)*(1-m/100)) + 0.07217 * ((1-k/100)*(1-y/100));
        double tz=0.01933 * ((1-k/100)*(1-c/100)) + 0.11919 * ((1-k/100)*(1-m/100)) + 0.95030 * ((1-k/100)*(1-y/100));

        return new CIExyz(tx, ty, tz);
    }
}

/**
 * @brief CYMK::getComponent
 * @return QVector<double> with the cyan, yellow, magenta, key black component of the color in CYMK
 */
QVector<double> CYMK::getComponents() const{
    QVector<double> to_return={static_cast<double>(cyan), static_cast<double>(yellow), static_cast<double>(magenta), static_cast<double>(key_black)};
    return to_return;
}

/**
 * @brief CYMK::getNumberOfComponets
 * @return int componets number
 */
int CYMK::getNumberOfComponets() const{
    return CYMK::componets;
}

/**
 * @brief CYMK::setComponents set the components inside the object
 * @param componets
 */
void CYMK::setComponents(QVector<double> componets){
    QVector<double> tcie;
    tcie.append(0.41245 * ((1-componets[3]/100)*(1-componets[0]/100)) + 0.35757 * ((1-componets[3]/100)*(1-componets[2]/100)) + 0.18043 * ((1-componets[3]/100)*(1-componets[1]/100)));
    tcie.append(0.21267 * ((1-componets[3]/100)*(1-componets[0]/100)) + 0.71515 * ((1-componets[3]/100)*(1-componets[2]/100)) + 0.07217 * ((1-componets[3]/100)*(1-componets[1]/100)));
    tcie.append(0.01933 * ((1-componets[3]/100)*(1-componets[0]/100)) + 0.11919 * ((1-componets[3]/100)*(1-componets[2]/100)) + 0.95030 * ((1-componets[3]/100)*(1-componets[1]/100)));
    CIExyz::setComponents(tcie);
    cyan=static_cast<unsigned int>(componets[0]);
    yellow=static_cast<unsigned int>(componets[1]);
    magenta=static_cast<unsigned int>(componets[2]);
    key_black=static_cast<unsigned int>(componets[3]);
}
