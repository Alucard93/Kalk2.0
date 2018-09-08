QT += gui core widgets

CONFIG += c++11
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
    Controller/controller.cpp \
    Model/Color/CIE_xyz/cie_xyz.cpp \
    Model/Color/CYMK/cymk.cpp \
    Model/Color/HSL/hsl.cpp \
    Model/Color/RGB/rgb.cpp \
    Model/Color/YUV/yuv.cpp \
    Model/Color/color.cpp \
    View/Console/consoleview.cpp \
    View/Gui/mainwindow.cpp \
    main.cpp \
    Model/Factory/colorfactory.cpp \
    Model/colormodel.cpp \
    View/Gui/historywindow.cpp


HEADERS += \
    Controller/controller.h \
    Model/Color/CIE_xyz/cie_xyz.h \
    Model/Color/CYMK/cymk.h \
    Model/Color/HSL/hsl.h \
    Model/Color/RGB/rgb.h \
    Model/Color/YUV/yuv.h \
    Model/Color/color.h \
    Model/illegalcolorexception.h \
    View/Console/consoleview.h \
    View/Gui/mainwindow.h \
    View/view.h \
    Controller/controller.h \
    Model/Factory/colorfactory.h \
    Model/Factory/genericfactory.h \
    Model/Factory/factory.h \
    Model/colormodel.h \
    Model/model.h \
    View/Gui/historywindow.h



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
