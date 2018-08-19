#ifndef COLORFACTORY_H
#define COLORFACTORY_H
#include "../classesused.h"
class ColorFactory{
public:
    static Color* GetNewColor(int type);
    static Color* Execution(Color* left, int operation, Color* right=nullptr);
    static Color* Execution(Color* left, int operation, int right=1);
    static const QVector<QString> AllTypes;
    static QVector<QString> availableOperations();
    static QVector<QString> permittedOperations(QString type);
    static QVector<QString> typeByOperation(int operation);
    static int getTypeSize();
};

#endif // COLORFACTORY_H
