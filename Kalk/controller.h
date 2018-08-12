#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include <model.h>
//#include <view.h>

class Controller:public QObject{
    Q_OBJECT
private:
    Model* model;
    //View* view;
public:
    Controller(Model* f_model); //View* f_view
public slots:
    void setLeftType(QString type);
    void setLeftValue(QVector<QString> values);
    void setRightType(QString type);
    void setRightValue(QVector<QString> values);
    void setOperation(QString operation);
    void getResult();
};

#endif // CONTROLLER_H
