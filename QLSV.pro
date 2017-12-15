#-------------------------------------------------
#
# Project created by QtCreator 2017-10-17T15:13:32
#
#-------------------------------------------------

QT       += core gui sql axcontainer\
            multimedia
QT       += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QLSV
TEMPLATE = app


# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

  INCLUDEPATH = c:/libxl-3.8.1.0/include_cpp
 LIBS += c:/libxl-3.8.1.0/lib/libxl.lib
SOURCES += \
        main.cpp \
        khoacntt.cpp \
    menudialog.cpp \
    quanlythongtin.cpp \
    quanlyketquahoctap.cpp \
    quanlylophoc.cpp \
    hoso.cpp \
    themthongtin.cpp \
    themlophoc.cpp \
    trangchu.cpp \
    dangky.cpp \
    quenmatkhau.cpp \
    doimatkhau.cpp

HEADERS += \
        khoacntt.h \
    menudialog.h \
    quanlythongtin.h \
    quanlyketquahoctap.h \
    quanlylophoc.h \
    hoso.h \
    themthongtin.h \
    themlophoc.h \
    trangchu.h \
    include_cpp/enum.h \
    include_cpp/IAutoFilterT.h \
    include_cpp/IBookT.h \
    include_cpp/IFilterColumnT.h \
    include_cpp/IFontT.h \
    include_cpp/IFormatT.h \
    include_cpp/ISheetT.h \
    include_cpp/libxl.h \
    include_cpp/setup.h \
    dangky.h \
    quenmatkhau.h \
    doimatkhau.h

FORMS += \
        khoacntt.ui \
    menudialog.ui \
    quanlythongtin.ui \
    quanlyketquahoctap.ui \
    quanlylophoc.ui \
    hoso.ui \
    themthongtin.ui \
    themlophoc.ui \
    trangchu.ui \
    dangky.ui \
    quenmatkhau.ui \
    doimatkhau.ui
