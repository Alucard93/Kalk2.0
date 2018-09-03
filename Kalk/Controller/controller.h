/**
 * @file controller.h
 * @author Gianmarco Pettinato
 * @class Controller
 * @date 15/08/2018
 * @brief this class manage the connection between model and view *
 */
#include <QObject>
#include "../Model/colormodel.h"
#include "../View/view.h"
#ifndef CONTROLLER_H
#define CONTROLLER_H
class Controller:public QObject{
    Q_OBJECT
private:
    Model* model;
    View* view;
    void disconnect();
    void connect();
public:
    Controller(Model* f_model, View* f_view);
    void setUp();

public slots:
    void newModel();
    void setClone();
    //void oldResult();
};

#endif // CONTROLLER_H
