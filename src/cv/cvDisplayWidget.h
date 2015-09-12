#ifndef CVDISPLAYWIDGET_H
#define CVDISPLAYWIDGET_H

#include <QWidget>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

namespace cv
{
    class VideoCapture;
}
class cvImageWidget;

class cvDisplayWidget : public QWidget
{
    Q_OBJECT
public:
    explicit cvDisplayWidget(QWidget *parent = 0);

signals:
    void newFrame(const cv::Mat&);

public slots:

protected:
    virtual void timerEvent(QTimerEvent *);
    virtual void initialiseVideoCapture();
    virtual void keyPressEvent(QKeyEvent *);
    virtual void mousePressEvent(QMouseEvent *);

private:
    cvImageWidget *mcvImageWidget;
    cv::Mat mMatImage;
    cv::VideoCapture *mVideoCapture;
};

#endif // CVDISPLAYWIDGET_H
