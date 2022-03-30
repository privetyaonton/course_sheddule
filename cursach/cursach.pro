QT       -= core gui
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addgroupclass.cpp \
    addgroupwindow.cpp \
    addsheddule.cpp \
    adduserlist.cpp \
    class.cpp \
    db.cpp \
    group.cpp \
    infogroupwindow.cpp \
    listclass.cpp \
    listgroup.cpp \
    main.cpp \
    mainwindow.cpp \
    windowlogin.cpp \
    windowsigninuser.cpp \
    windowvoicelogout.cpp

HEADERS += \
    addgroupclass.h \
    addgroupwindow.h \
    addsheddule.h \
    adduserlist.h \
    class.h \
    db.h \
    group.h \
    infogroupwindow.h \
    listclass.h \
    listgroup.h \
    mainwindow.h \
    windowlogin.h \
    windowsigninuser.h \
    windowvoicelogout.h

FORMS += \
    addgroupwindow.ui \
    addsheddule.ui \
    infogroupwindow.ui \
    mainwindow.ui \
    windowlogin.ui \
    windowsigninuser.ui \
    windowvoicelogout.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
