#include "cvFeatureExtractor.h"

#include "src/cv/cvDisplayWidget.h"
#include <iostream>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>

static int min, max, multiply;
cvFeatureExtractor::cvFeatureExtractor(cvDisplayWidget *widget) : QObject(widget)
{
    setObjectName("cvFeatureExtractor");

    if (!widget){
        std::cerr << "Error: cvDisplayWidget needed!";
    }
    mcvDisplayWidget = widget;
    /// Create Trackbar to choose type of Threshold
    cv::namedWindow("threshMap", CV_WINDOW_AUTOSIZE);
    cv::createTrackbar( "Min: ", "threshMap", &min, 255, 0 );
    cv::createTrackbar( "Max: ", "threshMap", &max, 255, 0 );
    cv::createTrackbar( "Multiple: ", "threshMap", &multiply, 1000, 0 );
    connect(mcvDisplayWidget, SIGNAL(newFrame(const cv::Mat&)), this, SLOT(extract(const cv::Mat&)));
}

void cvFeatureExtractor::extract(const cv::Mat& srcFrame)
{
    extractForeground(srcFrame, "background.jpg");
    extractSIFTFeatures(srcFrame, "sift.jpg");
}
void cvFeatureExtractor::extractSIFTFeatures(const cv::Mat& srcFrame, std::string referencePath) {
    cv::Mat backgroundMat = cv::imread(referencePath);
}

void cvFeatureExtractor::extractForeground(const cv::Mat& srcFrame, std::string backgroundPath)
{
    cv::Mat backgroundMat = cv::imread(backgroundPath, CV_LOAD_IMAGE_GRAYSCALE);
    cv::Mat srcMatGray, threshMap, erodeMap, dilateMap, dilateMap2, diffMat, kernel;
    int erosionSize = 2;
    kernel = cv::getStructuringElement( cv::MORPH_ELLIPSE, cv::Size( 2 * erosionSize + 1, 2 * erosionSize + 1 ), cv::Point(erosionSize, erosionSize));
    cvtColor(srcFrame, srcMatGray, CV_BGR2GRAY);
    diffMat = (backgroundMat - srcMatGray) * 10;
    cv::threshold(diffMat, threshMap, 200, 255, 0);
    cv::erode(threshMap, erodeMap, kernel);
    cv::dilate(erodeMap, dilateMap, kernel);
    cv::dilate(dilateMap, dilateMap2, kernel);
    cv::dilate(dilateMap2, dilateMap, kernel);
    cv::erode(dilateMap2, erodeMap, kernel);
    cv::imshow("bg mat", backgroundMat);
    cv::imshow("threshMap", threshMap);
    cv::imshow("diffmat", diffMat);
    cv::imshow("erodemap", erodeMap);
    cv::imshow("dilateMap", dilateMap);
    cv::imshow("dilateMap2", dilateMap2);
}
