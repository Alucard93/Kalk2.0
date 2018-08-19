#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include "../Model/model.h"
#include "../View/view.h"

class Controller:public QObject{
    Q_OBJECT
private:
    Model* model;
    View* view;
public:
    Controller(Model* f_model, View* f_view);
    void setUp();
    void connect();
};

#endif // CONTROLLER_H
