#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QHBoxLayout>

#include "src/games/GameListWidget.h"
#include "src/cv/cvDisplayWidget.h"
#include "src/cv/cvFeatureExtractor.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initialiseUI();
    loadGames();
}

void MainWindow::initialiseUI()
{
    QHBoxLayout *mainLayout = new QHBoxLayout();
    this->centralWidget()->setLayout(mainLayout);

    this->mGameListWidget = new GameListWidget();
    mainLayout->addWidget(this->mGameListWidget);

    this->mcvDisplayWidget = new cvDisplayWidget();
    mainLayout->addWidget(this->mcvDisplayWidget);

    this->mFeatureExtractor = new cvFeatureExtractor(mcvDisplayWidget);
}

void MainWindow::loadGames()
{
    // TODO:
    return;
}

MainWindow::~MainWindow()
{
    delete ui;
}
