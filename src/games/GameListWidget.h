#ifndef GAMELISTWIDGET_H
#define GAMELISTWIDGET_H

#include <QWidget>

class QListView;

class GameListWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameListWidget(QWidget *parent = 0);

signals:

public slots:

private:
    QListView *mGameThumbnailView;
};

#endif // GAMELISTWIDGET_H
