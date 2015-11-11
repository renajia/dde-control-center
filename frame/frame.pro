QT += widgets dbus svg

HEADERS    = frame.h \
             interfaces.h \
    homescreen.h \
    modulemetadata.h \
    constants.h \
    sidebar.h \
    contentview.h \
    dtipsframe.h \
    dbus/dbuscontrolcenter.h \
    dbus/dbusxmousearea.h \
    ../modules/display/dbus/displayinterface.h \
    dbus/dbuscontrolcenterservice.h \
    pluginsmanager.h
SOURCES    = frame.cpp \
             main.cpp \
    homescreen.cpp \
    sidebar.cpp \
    contentview.cpp \
    dtipsframe.cpp \
    dbus/dbuscontrolcenter.cpp \
    dbus/dbusxmousearea.cpp \
    ../modules/display/dbus/displayinterface.cpp \
    dbus/dbuscontrolcenterservice.cpp \
    pluginsmanager.cpp

include(../cutelogger/cutelogger.pri)
TARGET     = dde-control-center
DESTDIR    = $$_PRO_FILE_PWD_/../

CONFIG += c++11

LIBS += -ldui -L../widgets -lwidgets

RESOURCES += \
    qss.qrc \
    images.qrc

INCLUDEPATH    += ../widgets ../modules/display
