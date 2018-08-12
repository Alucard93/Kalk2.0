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
    //view->setOperation();
}

void Controller::setLeftValue(QVector<QString> values){
    QVector<double> modelValues;
    QString value;
    foreach(value, values){
        modelValues.push_back(value.toDouble());
    }
    model->setLeftValues(modelValues);
}

void Controller::setRightType(QString type){
    model->setRightType(type);
    QVector<QString> ops = model->availableOperation();
    QString op;
    //view->setOperation();
}

void Controller::setRightValue(QVector<QString> values){
    QVector<double> modelValues;
    QString value;
    foreach(value, values){
        modelValues.push_back(value.toDouble());
    }
    model->setRightValues(modelValues);
}

void Controller::setOperation(int operation){
    model->setOP(operation);
}
