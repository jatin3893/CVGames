#ifndef CVIMAGEWIDGET_H
#define CVIMAGEWIDGET_H

#include <QWidget>

#include <opencv2/core/core.hpp>

class QImage;

class cvImageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit cvImageWidget(QWidget *parent = 0);
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

signals:

public slots:
    void showImage(const cv::Mat& image);

protected:
    virtual void paintEvent(QPaintEvent *);

private:
    QImage *mImage;
    cv::Mat mMatImage;
};

#endif // CVIMAGEWIDGET_H
