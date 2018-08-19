#include "colorfactory.h"
const QVector<QString> ColorFactory::AllTypes={
  "ciexyz","cymk","hsl","rgb"
};

Color* ColorFactory::GetNewColor(int type){
    switch (type) {
    case 0: //return new CIExyz();
        break;
    case 1: //return new CYMK();
        break;
    case 2: //return new HSL();
        break;
    case 3: //return new RGB();
        break;
    default:
        throw new IllegalColorException("Selected color rappresentation is missing");
    }
}

Color* ColorFactory::Execution(Color* left, int operation, Color* right){
    switch (operation) {
    case 0: return left->negate();
    case 1: return left->mix(right);

    }
    return nullptr;
}

Color* ColorFactory::Execution(Color* left, int operation, int right){
    switch (operation) {
    case 2: return left->operator/(right);
    }
    return nullptr;
}

QVector<QString> ColorFactory::availableOperations(){
    QVector<QString> toReturn;
    for(int i=0; i<3; i++)
        toReturn.push_back(Color::allOpts[i][0]);
    return toReturn;

}
static QVector<QString> permittedOperations(QString type);
static QVector<QString> typeByOperation(int operation);
static int getTypeSize();
