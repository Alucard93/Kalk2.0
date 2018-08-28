#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include "../Model/colormodel.h"
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
public slots:
    void newModel();
    void oldResult();
};

#endif // CONTROLLER_H
