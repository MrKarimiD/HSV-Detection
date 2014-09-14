#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "opencv2/core/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <QDebug>
#include "QString"
#include "QFileDialog"
#include "imageprocessing.h"
#include "QTimer"
#include <QXmlStreamReader>
#include <QFile>
#include "QMouseEvent"
#include "QString"
#include "QSemaphore"
#include "QMessageBox"
#include "Color_Protobuf/ColorSettings.pb.h"
#include <iostream>
#include <fstream>
#include "QRubberBand"
#include "camerasetting.h"

using namespace cv;
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_open_button_clicked();

    void cam_timeout();

    void on_camSet_checkBox_stateChanged();

    void callImageProcessingFunctions(Mat input_mat);

    void on_xml_checkBox_stateChanged();

    void on_xml_button_clicked();

    //-----camera setting changed----------------
    void on_blue_slider_sliderMoved(int position);

    void on_red_slider_sliderMoved(int position);

    void on_exposure_slider_sliderMoved(int position);

    void on_brightness_slider_sliderMoved(int position);

    void updateCameraSetting();

    void setCameraSetting();

    void on_sharpness_slider_sliderMoved(int position);

    void on_gain_slider_sliderMoved(int position);
    //---------------------------------------------

    //-------Mouse Functions---------
    bool eventFilter(QObject *obj, QEvent *event);

    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    void mouseReleaseEvent(QMouseEvent *event);

    //-------------------------------

    void on_redSelect_button_clicked();

    void on_blueSelect_button_clicked();

    void on_greenSelect_button_clicked();

    void on_yellowSelect_button_clicked();

    void on_violetSelect_button_clicked();

    void on_cyanSelect_button_clicked();

    void on_blackSelect_button_clicked();

    void on_save_set_button_clicked();

    void on_open_set_button_clicked();

    void on_add_red_button_clicked();

    void on_add_blue_button_clicked();

    void on_add_green_button_clicked();

    void on_add_yellow_button_clicked();

    void on_add_violet_button_clicked();

    void on_add_cyan_button_clicked();

    void on_add_black_button_clicked();

    void on_cancel_button_clicked();

    void on_clear_red_button_clicked();

    void on_clear_blue_button_clicked();

    void on_clear_green_button_clicked();

    void on_clear_yellow_button_clicked();

    void on_clear_violet_button_clicked();

    void on_clear_cyan_button_clicked();

    void on_clear_black_button_clicked();

    void on_hue_slider_sliderMoved(int position);

    void on_saturation_slider_sliderMoved(int position);

    void on_contrast_slider_sliderMoved(int position);

private:
    Ui::MainWindow *ui;
    ImageProcessing *imageProcessor;
    QTimer *cam_timer,*send_timer;
    VideoCapture cap;
    bool cameraIsOpened,mouseButtonClicked,firstPointSelectedIsValid,imProcDataAvailable;
    bool permissionForSending;
    cameraSetting *camSetting;
    QSemaphore *semaphore;
    bool colorMode;
    bool stallMode;
    QString whichColor;
    QPoint origin;
    QRubberBand *rubberBand;
    Mat frameForColorDetection;
    QSemaphore *semaphoreForColorImage;
    QSemaphore *access2StallMode;

    void enableCameraSetting();

    void disableCameraSetting();

    void enableXML();

    void disableXML();

    bool isValidPlaceForSelect(int x,int y);

   void openSetting(QString fileAddress);

signals:
    void imageReady(Mat image);
    void cameraSettingChanged();
};

#endif // MAINWINDOW_H
