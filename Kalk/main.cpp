/**
 * @file main.cpp
 * @authors Giuseppe Bitetti & Gianmarco Pettinato
 * @date 30/08/2018
 */
#include <iostream>
#include <Model/colormodel.h>
#include <Controller/controller.h>
#include <View/Console/consoleview.h>
#include <View/Gui/mainwindow.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model* mainModel = new ColorModel();
    View* mainView;
    QString consoleinput = QString::fromLatin1(argv[1]);
    if(consoleinput=="-c")
        mainView = new ConsoleView();
    else
        mainView = new MainWindow();
    Controller* mainController=new Controller(mainModel,mainView);

    mainView->show();

    int resultCode;

    if(consoleinput!="-c")
        resultCode = a.exec();
    else
        resultCode = 0;

    delete mainController;

    return resultCode;

}
