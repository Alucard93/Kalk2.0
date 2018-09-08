#include "cymk.h"

/**
 * @brief CYMK::CYMK Constructor for CYMK color representation from unsigned int numbers
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
 * @brief CYMK::CYMK Constructor for CYMK color representation from Color pointer
 * @throws IllegalColorException
 * @param from
 */
CYMK::CYMK(const Color* from) : CIExyz(from){
    QVector<double> xyz=CIExyz::getComponents();
    double _r=3.063219*xyz[0] -1.393326*xyz[1] -0.475801*xyz[2];
    double _g=-0.969245*xyz[0] +1.875968*xyz[1] +0.041555*xyz[2];
    double _b=0.067872*xyz[0] -0.228833*xyz[1] +1.069251*xyz[2];
    double _c=1-_r;
    double _m=1-_g;
    double _y=1-_b;
    double _k=1-std::max({_r,_g,_b});
    double k=_k*100;
    double c=((_c-_k)/(1-_k))*100;
    double m=((_m-_k)/(1-_k))*100;
    double y=((_y-_k)/(1-_k))*100;
    if((c>upper_limit_cymk || y>upper_limit_cymk || m>upper_limit_cymk || k>upper_limit_cymk))
        throw IllegalColorException(getRepresentation().toStdString()+": valori non accettabili");
    cyan=static_cast<unsigned int>(c);
    yellow=static_cast<unsigned int>(y);
    magenta=static_cast<unsigned int>(m);
    key_black=static_cast<unsigned int>(k);
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
 * @brief CYMK::getrepresentation
 * @return QString that contains name of the object
 */
QString CYMK::getRepresentation() const{
    return QString("CYMK");
}

/**
 * @brief CYMK::negate
 * @return Color pointer with a new color with the negated values
 */
Color* CYMK::negate() const{
    return new CYMK(upper_limit_cymk-cyan, upper_limit_cymk-yellow, upper_limit_cymk-magenta, key_black);
}

/**
 * @brief CYMK::mix
 * @param a
 * @return Color pointer with a new color mixed as CYMK
 */
Color* CYMK::mix(const Color* a)const{
    return new CYMK(CIExyz::mix(a));
}

/**
 * @brief CYMK::getCIE
 * @param c
 * @param y
 * @param m
 * @param k
 * @throws IllegalColorException
 * @return Color pointer with a clone of *this in the CIExyz format
 */
Color* CYMK::getCIE(unsigned int c, unsigned int y, unsigned int m, unsigned int k) const{
    if((c>upper_limit_cymk || y>upper_limit_cymk || m>upper_limit_cymk || k>upper_limit_cymk))
        throw IllegalColorException(getRepresentation().toStdString()+": valori non accettabili");
    double tx=0.41245 * ((1-k/100)*(1-c/100)) + 0.35757 * ((1-k/100)*(1-m/100)) + 0.18043 * ((1-k/100)*(1-y/100));
    double ty=0.21267 * ((1-k/100)*(1-c/100)) + 0.71515 * ((1-k/100)*(1-m/100)) + 0.07217 * ((1-k/100)*(1-y/100));
    double tz=0.01933 * ((1-k/100)*(1-c/100)) + 0.11919 * ((1-k/100)*(1-m/100)) + 0.95030 * ((1-k/100)*(1-y/100));
    return new CIExyz(tx, ty, tz);

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
 * @return number of componets
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

/**
 * @brief CYMK::getLimits
 * @return limits of CYMK as QVector<QString>
 */
QVector<QString> CYMK::getLimits() const{
    return {"Cyan",QString::number(lower_limit_cymk),QString::number(upper_limit_cymk),
            "Yellow",QString::number(lower_limit_cymk),QString::number(upper_limit_cymk),
            "Magenta",QString::number(lower_limit_cymk),QString::number(upper_limit_cymk),
            "Key Black",QString::number(lower_limit_cymk),QString::number(upper_limit_cymk)};
}
