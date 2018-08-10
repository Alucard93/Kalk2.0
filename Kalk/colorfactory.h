#ifndef COLORFACTORY_H
#define COLORFACTORY_H
#include <classesused.h>
class ColorFactory{
public:
    static Color* GetNewColor(QString type,QVector<double> values);
    static QVector<QString> GetTypes();
};

#endif // COLORFACTORY_H
