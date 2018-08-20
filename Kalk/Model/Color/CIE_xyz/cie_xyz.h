#ifndef CIE_XYZ_H
#define CIE_XYZ_H

#include <QString>
#include "../color.h"

class CIExyz : public Color{
public:
    CIExyz(double t_x=0, double t_y=0, double t_z=0);
    CIExyz(const Color* c);
    int getNumberOfComponets() const;
    void setComponents(QVector<double> componets);
    QString getRappresentation() const;
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

Q_DECLARE_METATYPE(CIExyz)
#endif // CIE_XYZ_H
