#include<controller.h>
Controller::Controller(Model* fmodel){
    model = fmodel;
}

void Controller::setLeftType(QString type){
    model->setLeftType(type);
    QVector<QString> ops = model->availableOperation();
    QString op;
    foreach(op, ops){
        std::cout<<op.utf16();
    }
}

void Controller::setLeftValue(QVector<QString> values){
    model->setLeftValues(values);
}
