#ifndef IMAGEPROCESSING_H
#define IMAGEPROCESSING_H
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <QDebug>
#include "QString"
#include "QFileDialog"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/nonfree/cuda.hpp>
#include "Constants.h"

using namespace cv;
using namespace std;

#include <QObject>

class ImageProcessing : public QObject
{
    Q_OBJECT
public:
    explicit ImageProcessing(QObject *parent = 0);

    Mat undistortImage(Mat input);

    Mat applyFilters(Mat input);

    vector<Vec3f> returnColor(Mat input, Mat src);

    void changeOutputSetting(bool con,bool geom,bool bound,bool rotate,bool boundries);

    Mat returnAdaptiveThreshlodImage();

    Mat returnThreshlodImage();

    Mat returnCannyImage();

    Mat returnCropedImage();

    Mat Outputs[5];//0->Crop    1->Adaptive    2->threshold   3->canny     4->final

    QList<Vec3f> min_red_samples;
    QList<Vec3f> max_red_samples;

    QList<Vec3f> min_blue_samples;
    QList<Vec3f> max_blue_samples;

    QList<Vec3f> min_green_samples;
    QList<Vec3f> max_green_samples;

    QList<Vec3f> min_yellow_samples;
    QList<Vec3f> max_yellow_samples;

    QList<Vec3f> min_cyan_samples;
    QList<Vec3f> max_cyan_samples;

    QList<Vec3f> min_violet_samples;
    QList<Vec3f> max_violet_samples;

    QList<Vec3f> min_black_samples;
    QList<Vec3f> max_black_samples;

private:
    vector<Vec3f> finding_circles;
    cv::Size imSize;
    //Mat cameraMatrix, distCoeffs;
    bool drawContoursBool,drawGeometricLabels,drawBoundedRect,drawRotatedRect,drawBoundries;

    bool checkAspectRatio(vector<Point> contours_poly);

    bool checkAspectRatioForRotatedRect(RotatedRect input);

    double angle(cv::Point pt1, cv::Point pt2, cv::Point pt0);

    void setLabel(cv::Mat& im, const std::string label, std::vector<cv::Point>& contour,Rect cropedRect);

    bool colorIsInRange(Vec3b inputColor,Vec3b sourceColor);

signals:

public slots:

};

#endif // IMAGEPROCESSING_H
