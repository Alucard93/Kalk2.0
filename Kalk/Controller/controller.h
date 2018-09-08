/**
 * @file controller.h
 * @author Gianmarco Pettinato
 * @class Controller
 * @date 15/08/2018
 * @brief this class handles the connection between model and view
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
public:
    Controller(Model* f_model, View* f_view);
    ~Controller();
    void connect();
    void disconnect();
public slots:
    void setUp();
};

#endif // CONTROLLER_H
