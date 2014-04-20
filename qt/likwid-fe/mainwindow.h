#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
class PlotArea;
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
    Ui::PlotArea *plotArea;


public slots:
    void selectApp();
    void runApp();
};

#endif // MAINWINDOW_H
