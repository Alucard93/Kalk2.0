#include <iostream>
#include <Model/model.h>
#include <Controller/controller.h>
#include <View/consoleview.h>
int main(int argc, char *argv[])
{
    Model* mainModel = new Model();
    View* mainView;
    if(strncmp(argv[1],"-c",0)==0){
        mainView = new ConsoleView();
    }else{
        mainView = new ConsoleView();
    }
    Controller* mainController = new Controller(mainModel,mainView);
    return 0;
}
