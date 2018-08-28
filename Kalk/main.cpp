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
    /**if(strcmp(argv[1],"-c"))
        mainView = new ConsoleView();
    else**/
    mainView = new MainWindow();
    Controller* mainController=new Controller(mainModel,mainView);

    mainView->show();

    return a.exec();
}
