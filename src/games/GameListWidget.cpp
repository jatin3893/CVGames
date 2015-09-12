#include "GameListWidget.h"

#include <QVBoxLayout>
#include <QListView>

GameListWidget::GameListWidget(QWidget *parent) : QWidget(parent)
{
    setObjectName("GameListWidget");

    this->setLayout(new QVBoxLayout());
    mGameThumbnailView = new QListView();
    this->layout()->addWidget(mGameThumbnailView);
}

