#include "imageprocessing.h"

ImageProcessing::ImageProcessing(QObject *parent) :
    QObject(parent)
{
    drawBoundedRect=false;
    drawContoursBool=false;
    drawGeometricLabels=false;
    drawRotatedRect=false;
    drawBoundries=false;
}

vector<Vec3f> ImageProcessing::returnColor(Mat input,Mat src)
{
    Mat HSV,show;
    cvtColor(input,HSV,COLOR_RGB2HSV);
    cvtColor(src,show,COLOR_RGB2HSV);

    vector<cv::Mat> hsvPlanes;
    vector<cv::Mat> hsvPlanes_show;
    split(HSV, hsvPlanes);
    split(show, hsvPlanes_show);

    // compute statistics for Hue value
    Scalar means, stddev;
    meanStdDev(hsvPlanes[0], means, stddev);

    // compute statistics for Saturation value
    Scalar means1, stddev1;
    meanStdDev(hsvPlanes[1], means1, stddev1);

    // compute statistics for Value value
    Scalar means2, stddev2;
    meanStdDev(hsvPlanes[2], means2, stddev2);

    // ensure we get 95% of all valid Hue samples (statistics 3*sigma rule)
    float minHue = means[0] - stddev[0]*3;
    float maxHue = means[0] + stddev[0]*3;

    float minSat = means1[0] - stddev1[0]*3;
    float maxSat = means1[0] + stddev1[0]*3;

    float minVal = means2[0] - stddev2[0]*3;
    float maxVal = means2[0] + stddev2[0]*3;

    // STEP 2: detection phase
    Mat imgThreshed;
    inRange(show, Scalar(minHue,minSat,minVal), Scalar(maxHue,maxSat,maxVal), imgThreshed);
    imshow("thresholded", imgThreshed);

    vector<Vec3f> out;

    Vec3f min;
    min.val[0]=minHue;
    min.val[1]=minSat;
    min.val[2]=minVal;

    Vec3f max;
    max.val[0]=maxHue;
    max.val[1]=maxSat;
    max.val[2]=maxVal;

    out.push_back(min);
    out.push_back(max);

    return out;
}

Mat ImageProcessing::undistortImage(Mat input)
{
    Mat cameraMatrix = Mat::eye(3, 3, CV_64F);

    cameraMatrix.at<double>(0,0) = 6.7055726712006776e+02;
    cameraMatrix.at<double>(0,1) = 0;
    cameraMatrix.at<double>(0,2) = 3.8950000000000000e+02;

    cameraMatrix.at<double>(1,0) = 0;
    cameraMatrix.at<double>(1,1) = 6.7055726712006776e+02;
    cameraMatrix.at<double>(1,2) = 2.8950000000000000e+02;

    cameraMatrix.at<double>(2,0) = 0;
    cameraMatrix.at<double>(2,1) = 0;
    cameraMatrix.at<double>(2,2) = 1;

    Mat distCoeffs = Mat::zeros(8, 1, CV_64F);

    distCoeffs.at<double>(0,0) = -3.7087470577837894e-01;
    distCoeffs.at<double>(1,0) = 1.8508542088322785e-01;
    distCoeffs.at<double>(2,0) = 0;
    distCoeffs.at<double>(3,0) = 0;
    distCoeffs.at<double>(4,0) = -3.4799226907590207e-02;

    Mat inputFrame;
    input.copyTo(inputFrame);

//    bitwise_not(inputFrame, inputFrame);

    Mat outputFrame;
//    undistort(input,outputFrame,cameraMatrix,distCoeffs);
    Size imageSize = input.size();
    Mat view, rview, map1, map2;

    initUndistortRectifyMap(cameraMatrix, distCoeffs, Mat(),
        getOptimalNewCameraMatrix(cameraMatrix, distCoeffs, imageSize, 0, imageSize, 0),
        imageSize, CV_16SC2, map1, map2);
    view = inputFrame;
    remap(view, rview, map1, map2, INTER_LINEAR);

//    //blur(outputFrame,outputFrame,Size(3,3));
//    //imshow("dis",input);
////    imshow("undis",rview);
    return rview;
}

double ImageProcessing::angle(Point pt1, Point pt2, Point pt0)
{
    double dx1 = pt1.x - pt0.x;
    double dy1 = pt1.y - pt0.y;
    double dx2 = pt2.x - pt0.x;
    double dy2 = pt2.y - pt0.y;
    return (dx1*dx2 + dy1*dy2)/sqrt((dx1*dx1 + dy1*dy1)*(dx2*dx2 + dy2*dy2) + 1e-10);
}

void ImageProcessing::setLabel(Mat &im, const string label, std::vector<Point> &contour,Rect cropedRect)
{
    if(this->drawGeometricLabels)
    {
        int fontface = FONT_HERSHEY_SIMPLEX;
        double scale = 0.4;
        int thickness = 1;
        int baseline = 0;

        Size text = getTextSize(label, fontface, scale, thickness, &baseline);
        Rect r = boundingRect(contour);

        Point pt(r.x + ((r.width - text.width) / 2), r.y + ((r.height + text.height) / 2));
        pt.x+=cropedRect.x;
        pt.y+=cropedRect.y;
        rectangle(im, pt + Point(0, baseline), pt + Point(text.width, -text.height), CV_RGB(255,255,255), CV_FILLED);
        putText(im, label, pt, fontface, scale, CV_RGB(0,0,0), thickness, 8);
    }
}

bool ImageProcessing::colorIsInRange(Vec3b inputColor, Vec3b sourceColor)
{
//    if( (abs(inputColor.val[0]-sourceColor.val[0]) < ColorThresh) &&  (abs(inputColor.val[1]-sourceColor.val[1]) < ColorThresh)
//        && (abs(inputColor.val[2]-sourceColor.val[2]) < ColorThresh) )
//    {
//        return true;
//    }
//    else
//        return false;
    double aucqodean_dis =sqrt(pow(inputColor.val[0]-sourceColor.val[0],2)+pow(inputColor.val[1]-sourceColor.val[1],2)
            +pow(inputColor.val[2]-sourceColor.val[2],2 ));
    double reference_dis = 441.67295593;

    if( (aucqodean_dis/reference_dis)*100 < ColorPercentage )
    {
        return true;
    }
    else
        return false;


}

void ImageProcessing::changeOutputSetting(bool con, bool geom, bool bound, bool rotate,bool boundries)
{
    this->drawContoursBool=con;
    this->drawGeometricLabels=geom;
    this->drawBoundedRect=bound;
    this->drawRotatedRect=rotate;
    this->drawBoundries=boundries;
}

Mat ImageProcessing::returnAdaptiveThreshlodImage()
{
    return Outputs[1];
}

Mat ImageProcessing::returnThreshlodImage()
{
    return Outputs[2];
}

Mat ImageProcessing::returnCannyImage()
{
    return Outputs[3];
}

Mat ImageProcessing::returnCropedImage()
{
    return Outputs[0];
}

bool ImageProcessing::checkAspectRatio(vector<Point> contours_poly)
{
    Rect boundedRect=boundingRect( Mat(contours_poly) );
    double aspect_ratio = float(boundedRect.width)/boundedRect.height;
    bool out;

    if(  (aspect_ratio>ASPECT_RATIO_TRESH) || (aspect_ratio<(1/ASPECT_RATIO_TRESH)))
        out=false;
    else
        out=true;

    return out;
}

bool ImageProcessing::checkAspectRatioForRotatedRect(RotatedRect input)
{
    double aspect_ratio = float(input.size.width)/input.size.height;
    bool out=true;

    if(  (aspect_ratio>ASPECT_RATIO_TRESH) || (aspect_ratio<(1/ASPECT_RATIO_TRESH)))
        out=false;

    return out;
}
