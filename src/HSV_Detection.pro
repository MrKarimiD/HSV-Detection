#-------------------------------------------------
#
# Project created by QtCreator 2014-08-04T12:33:35
#
#-------------------------------------------------

QT       += core gui xml network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ShapeDetection
TEMPLATE = app
unix:  LIBS += -lprotobuf

INCLUDEPATH += geom
INCLUDEPATH += Prototype_Messages

SOURCES += main.cpp\
        mainwindow.cpp \
    imageprocessing.cpp \
    camerasetting.cpp \
    Color_Protobuf/ColorSettings.pb.cc

HEADERS  += mainwindow.h \
    imageprocessing.h \
    Constants.h \
    camerasetting.h \
    Color_Protobuf/ColorSettings.pb.h

FORMS    += mainwindow.ui

LIBS += -lopencv_core \
        -lopencv_highgui \
        -lopencv_imgproc \
        -lopencv_videostab \
        -lopencv_video \
        -lopencv_ts \
        -lopencv_stitching \
        -lopencv_superres \
        -lopencv_photo \
        -lopencv_objdetect \
        -lopencv_nonfree \
        -lopencv_ml \
        -lopencv_legacy \
        -lopencv_calib3d \
        -lopencv_flann \
        -lopencv_contrib \
        -lopencv_features2d
