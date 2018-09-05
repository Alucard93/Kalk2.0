/**
 * @file cie_zyz.h
 * @authors Giuseppe Bitetti & Gianmarco Pettinato
 * @date 20/7/2018
 * @class Color
 * @brief this class is the main base for color rappresentation in this program
*/
#include <iostream>
#include <QVector>
#ifndef COLOR_H
#define COLOR_H
class Color{
public:
    Color()=default;
    virtual ~Color()=default;
    static const QString allOpts[3][3];
    //Class setup
    virtual int getNumberOfComponets() const =0; // returns how many componets the rappresentation needs
    virtual void setComponents(QVector<double> componets) =0;

    //Possible operations
    virtual Color* getCIE()const =0; //returns CIExyz class pointer
    virtual Color* negate()const =0; //returns in the current color rappresentation the negate color
    virtual Color* mix(const Color* c1)const =0; //returns in the current color rappresentation the result of mixing two color
    virtual Color* operator/(const int &div) const =0; //return in the current color rappresentation the division of its components

    //Getting current status
    //TODO virtual QVector<QString> getInfo() const =0;
    virtual QVector<QString> availableOperations() const =0; //returns a vector with the name of the method available and the Types can be used with it
    virtual QVector<double> getComponents() const =0;
    virtual QString getRappresentation() const =0;


};
#endif // COLOR_H
