#ifndef CVFEATUREEXTRACTOR_H
#define CVFEATUREEXTRACTOR_H

#include <QObject>
#include <opencv2/core/core.hpp>

class cvDisplayWidget;

class cvFeatureExtractor : public QObject
{
    Q_OBJECT
public:
    explicit cvFeatureExtractor(cvDisplayWidget *widget = 0);
    void extractForeground(const cv::Mat&, std::string);
    void extractSIFTFeatures(const cv::Mat&, std::string);

signals:

public slots:
    void extract(const cv::Mat& srcFrame);

private:
    cvDisplayWidget *mcvDisplayWidget;
};

#endif // CVFEATUREEXTRACTOR_H
