#include <model.h>
QStringList Model::availableTypes=(QStringList()<<"cie_xyz"<<"rgb"<<"hsl"<<"cymk");

Model::Model(const Model* previous):old(previous){
}

void Model::setLeftOperand(int type,const QVector<int>& data){
    left = new Operand(availableTypes[type]);
    left->setData(data);
}

void Model::setRightOperand(int type,const QVector<int>& data){
    right = new Operand(availableTypes[type]);
    right->setData(data);
}

QVector<QString> Model::availableOperation(){
    availableOp.push_back("getCie");
    try {
        left->l_op->getCIE();
    } catch (IllegalColorException& e) {
        if(!strcmp(e.what(),"operation not available"))
            availableOp.removeLast();
    }
    availableOp.push_back("getRappresentation");
    try {
        left->l_op->getRappresentation();
    } catch (IllegalColorException& e) {
        if(!strcmp(e.what(),"operation not available"))
            availableOp.removeLast();
    }
    availableOp.push_back("negate");
    try {
        left->l_op->negate();
    } catch (IllegalColorException& e) {
        if(!strcmp(e.what(),"operation not available"))
            availableOp.removeLast();
    }
    availableOp.push_back("mix");
    try {
        left->l_op->mix( new CIExyz() );
    } catch (IllegalColorException& e) {
        if(!strcmp(e.what(),"operation not available"))
            availableOp.removeLast();
    }
    return availableOp;
}

void Model::setOP(int eOperation){

}
