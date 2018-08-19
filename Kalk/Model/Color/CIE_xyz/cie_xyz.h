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
    static const double upper_limit_X;
    static const double lower_limit_X;
    static const double upper_limit_Y;
    static const double lower_limit_Y;
    static const double upper_limit_Z;
    static const double lower_limit_Z;
    static const int componets;
    static const QVector<QString> implementedMethods;
};

const double CIExyz::lower_limit_X=0;
const double CIExyz::upper_limit_X=0.95047;
const double CIExyz::lower_limit_Y=0;
const double CIExyz::upper_limit_Y=1.00000;
const double CIExyz::lower_limit_Z=0;
const double CIExyz::upper_limit_Z=1.08883;
const int CIExyz::componets=3;
const QVector<QString> CIExyz::implementedMethods={"negate","mix"};

Q_DECLARE_METATYPE(CIExyz)
#endif // CIE_XYZ_H
