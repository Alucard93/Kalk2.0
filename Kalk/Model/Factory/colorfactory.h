#include "../Color/color.h"
#include <QMap>

#ifndef GENERICFACTORY_H
#define GENERICFACTORY_H
class GenericFactory{
public:
    virtual Color* getNewColor() const =0;
};

#endif // GENERICFACTORY_H

#ifndef COLORFACTORY_H
#define COLORFACTORY_H
class ColorFactory{
private:
    static QMap<QString,GenericFactory*> allColorFactories;
    static bool firstexec;
public:
    static bool addColorFactory(QString,GenericFactory*);
    static QVector<QString> getAllColorTypes();
    static Color* GetNewColor(QString key);
    static Color* Execution(Color* left, int operation, Color* right=nullptr);
    static Color* Execution(Color* left, int operation, int right=1);
    static QVector<QString> availableOperations();
    static QVector<QString> permittedOperations(QString type);
    static QVector<QString> typeByOperation(int operation);
    static int getTypeSize();
};
#endif // COLORFACTORY_H

#ifndef TEMPLATE_FACTORY
#define TEMPLATE_FACTORY

template <class T> class Factory: public GenericFactory{
public:
    Color* getNewColor() const{
        return new T;
    }
};
#endif //TEMPLATE_FACTORY
