QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
    Controller/controller.cpp \
    Model/Color/CIE_xyz/cie_xyz.cpp \
    Model/Color/CYMK/cymk.cpp \
    Model/Color/HSL/hsl.cpp \
    Model/Color/RGB/rgb.cpp \
    Model/Color/colorfactory.cpp \
    Model/model.cpp \
    View/consoleview.cpp \
    View/mainwindow.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \ 
    Controller/controller.h \
    Model/Color/CIE_xyz/cie_xyz.h \
    Model/Color/CYMK/cymk.h \
    Model/Color/HSL/hsl.h \
    Model/Color/RGB/rgb.h \
    Model/Color/color.h \
    Model/Color/colorfactory.h \
    Model/classesused.h \
    Model/illegalcolorexception.h \
    Model/model.h \
    View/consoleview.h \
    View/view.h \
    View/mainwindow.h
