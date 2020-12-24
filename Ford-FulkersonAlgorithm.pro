QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Information.cpp \
    Last_results.cpp \
    Output_result.cpp \
    Print_last_results.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    AlgoritmFordFalkerson.h \
    CurSource_CurStock.h \
    Information.h \
    Last_results.h \
    Output_message.h \
    Output_result.h \
    Print_last_results.h \
    mainwindow.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
