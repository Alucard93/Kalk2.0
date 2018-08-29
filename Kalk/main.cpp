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

    if(consoleinput!="-c")
        return a.exec();
    else
        return 0;
}
