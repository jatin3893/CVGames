#include "cvDisplayWidget.h"

#include "cvImageWidget.h"

#include <iostream>
#include <QHBoxLayout>
#include <QKeyEvent>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

cvDisplayWidget::cvDisplayWidget(QWidget *parent) : QWidget(parent)
{
    setObjectName("cvDisplayWidget");
    setFocus();

    this->mcvImageWidget = new cvImageWidget();
    this->setLayout(new QHBoxLayout());
    this->layout()->addWidget(this->mcvImageWidget);

    this->initialiseVideoCapture();
}

void cvDisplayWidget::timerEvent(QTimerEvent *)
{
    *this->mVideoCapture >> this->mMatImage;
    this->mcvImageWidget->showImage(this->mMatImage);
    emit newFrame(this->mMatImage);
}

void cvDisplayWidget::initialiseVideoCapture()
{
    this->mVideoCapture = new cv::VideoCapture(0);
    if (!this->mVideoCapture->isOpened()){
        std::cerr << "Error opening Camera feed.";
        exit(-1);
    }
    this->startTimer(30);
}

void cvDisplayWidget::keyPressEvent(QKeyEvent *event)
{
    std::cout << "keyPressEvent();" << std::endl;
    switch(event->key()){
    case Qt::Key_S:
        cv::imwrite("background.jpg", this->mMatImage);
        std::cout << "Writing!" << std::endl;
        break;
    }
}

void cvDisplayWidget::mousePressEvent(QMouseEvent *)
{
    std::cout << "Mouse PReess" << std::endl;
    cv::imwrite("background.jpg", this->mMatImage);
    std::cout << "Writing!" << std::endl;
}
