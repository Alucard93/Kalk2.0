/**
 * @file cie_zyz.h
 * @author Gianmarco Pettinato
 * @date 20/7/2018
 * @class CIExyz
 * @brief this class uses the base class Color and implements a CIE xyz color space in D65 white point
 * CIExyz stores a color in CIE xyz whit a d65 white point representation
*/
#include "../../Factory/factory.h"
#ifndef CIE_XYZ_H
#define CIE_XYZ_H
class CIExyz : public Color{
public:
    //Default Constructor
    CIExyz(double t_x=0, double t_y=0, double t_z=0);

    //Copy Constructor
    CIExyz(const CIExyz& c);
    CIExyz(const Color* c);

    //Destructor
    ~CIExyz()=default;

    int getNumberOfComponets() const;
    QVector<QString> getLimits() const;
    void setComponents(QVector<double> componets);
    QString getRepresentation() const;
    Color* negate() const;
    Color* mix(const Color* c)const;
    Color* getCIE() const;
    Color* operator/(const int &div) const;
    QVector<QString> availableOperations() const;
    QVector<double>getComponents() const;

private:
    double x;
    double y;
    double z;
    constexpr static const double lower_limit_X=0;
    constexpr static const double upper_limit_X=0.95047;
    constexpr static const double lower_limit_Y=0;
    constexpr static const double upper_limit_Y=1.00000;
    constexpr static const double lower_limit_Z=0;
    constexpr static const double upper_limit_Z=1.08883;
    constexpr static const int componets=3;
    static const QVector<QString> implementedMethods;
};
static Factory<CIExyz> CIEFactory;//Registers the class in ColorFactory
#endif // CIE_XYZ_H
