#include <iostream>
#include <model.h>
#include <controller.h>
#include <consoleview.h>
int main(int argc, char *argv[])
{
    Model* mainModel = new Model();
    View* mainView;
    if(strncmp(argv[1],"-c",0)==0){
        mainView = new ConsoleView();
    }else{
        //mainView = new GuiView();
    }
    Controller* mainController = new Controller(mainModel,mainView);
    if(strncmp(argv[1],"-c",0)==0){
        mainController->setViewAvailableTypes();
    }else{
        //mainView = new GuiView();
    }
    return 0;
}
