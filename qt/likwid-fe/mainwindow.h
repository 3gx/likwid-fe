#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
class RenderArea;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString appNameString;
    Ui::RenderArea *renderArea;


public slots:
    void selectApp();
    void runApp();
};

#endif // MAINWINDOW_H
