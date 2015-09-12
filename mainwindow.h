#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class cvDisplayWidget;
class GameListWidget;
class cvFeatureExtractor;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    cvDisplayWidget *mcvDisplayWidget;
    GameListWidget *mGameListWidget;
    cvFeatureExtractor *mFeatureExtractor;

protected:
    void loadGames();
    void initialiseUI();
};

#endif // MAINWINDOW_H
