#include "colorfactory.h"
const QVector<QString> ColorFactory::AllTypes={"ciexyz","cymk","hsl","rgb"};

Color* ColorFactory::GetNewColor(int type){
    try {
        switch (type) {
        case 1:
            std::cout<<"CIExyz"<<"\n";
            return new CIExyz();
        case 2:
            std::cout<<"CYMK"<<"\n";
            return new CYMK();
        case 3:
            std::cout<<"HSL"<<"\n";
            return new HSL();
        case 4:
            std::cout<<"RGB"<<"\n";
            return new RGB();
        default:
            throw new IllegalColorException("Selected color rappresentation is missing");
        }
    } catch (IllegalColorException e) {
        std::cout<<e.what()<<'\n';
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
QVector<QString> ColorFactory::permittedOperations(QString type){
    int i=0;
    while (type!=AllTypes[i]) {
        i++;
    }
    Color* test = GetNewColor(i);
    return test->availableOperations();
}

QVector<QString> ColorFactory::typeByOperation(int operation){
    QVector<QString> toReturn;
    toReturn.push_back("Select type");
    if(operation!=-1){
        for(int i=1;i<3&&(!Color::allOpts[operation][i].isEmpty());i++){
            if(Color::allOpts[operation][i]=="color")
                toReturn+=ColorFactory::AllTypes;
            else
                toReturn.push_back(Color::allOpts[operation][i]);
        }
    }else{
        toReturn+=ColorFactory::AllTypes;
    }
    return toReturn;
}
