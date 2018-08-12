#include <model.h>

Model::Model(const Model* previous):old(previous){
}

void Model::setLeftOperand(QString type, QVector<double> data){
    left = ColorFactory::GetNewColor(type, data);
}

void Model::setRightOperand(QString type,const QVector<double> data){
    right = ColorFactory::GetNewColor(type, data);
}

QVector<QString> Model::availableTypes(){
    return ColorFactory::GetTypes();
}

QVector<QString> Model::availableOperation(){
    availableOp.push_back("getCie");
    try {
        left->getCIE();
    } catch (IllegalColorException& e) {
        if(!strcmp(e.what(),"operation not available"))
            availableOp.removeLast();
    }
    availableOp.push_back("getRappresentation");
    try {
        left->getRappresentation();
    } catch (IllegalColorException& e) {
        if(!strcmp(e.what(),"operation not available"))
            availableOp.removeLast();
    }
    availableOp.push_back("negate");
    try {
        left->negate();
    } catch (IllegalColorException& e) {
        if(!strcmp(e.what(),"operation not available"))
            availableOp.removeLast();
    }
    availableOp.push_back("mix");
    try {
        left->mix( new CIExyz() );
    } catch (IllegalColorException& e) {
        if(!strcmp(e.what(),"operation not available"))
            availableOp.removeLast();
    }
    return availableOp;
}

void Model::setOP(int eOperation){
    operation=availableOp[eOperation];
}

void Model::execute(){
    if(operation=="negate")
        result = left->negate();
}

QString Model::getResult(){
    return result->getRappresentation();
}

Model::~Model(){
    Model* local_old=const_cast<Model*>(old);
    while(local_old){
        Model* to_delete=local_old;
        local_old=const_cast<Model*>(local_old->old);
        if(to_delete->left)
            delete to_delete->left;
        if(to_delete->right)
            delete to_delete->right;
        if(to_delete->result)
            delete to_delete->result;
    }
}