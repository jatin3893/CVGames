#include "cvImageWidget.h"

#include <QImage>
#include <QPainter>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

cvImageWidget::cvImageWidget(QWidget *parent) : QWidget(parent)
{
    setObjectName("cvImageWidget");
    mImage = new QImage();
}

void cvImageWidget::showImage(const cv::Mat& image)
{
    assert(image.isContinuous());
    cv::cvtColor(image, this->mMatImage, CV_BGR2RGB);

    mImage = new QImage(this->mMatImage.data, this->mMatImage.cols, this->mMatImage.rows, this->mMatImage.cols * 3, QImage::Format_RGB888);
    this->setFixedSize(this->mMatImage.cols, this->mMatImage.rows);
    repaint();
}

QSize cvImageWidget::sizeHint() const
{
    return this->mImage->size();
}

QSize cvImageWidget::minimumSizeHint() const
{
    return this->mImage->size();
}

void cvImageWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.drawImage(QPoint(0, 0), *mImage);
    painter.end();
}
