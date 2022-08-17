QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adding.cpp \
    main.cpp \
    login.cpp \
    mainwindow.cpp \
    registration.cpp

HEADERS += \
    adding.h \
    login.h \
    mainwindow.h \
    registration.h

FORMS += \
    adding.ui \
    login.ui \
    mainwindow.ui \
    registration.ui

win32:RC_FILE = icon.rc
win64:RC_FILE = icon.rc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
