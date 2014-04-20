#include <QtGui>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "plotArea.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    plotArea(new Ui::PlotArea)
{
    ui->setupUi(this);
    this->setWindowTitle("likwid-fe");
    connect(ui->selectAppButton, SIGNAL(clicked()), this, SLOT(selectApp()));
    connect(ui->runAppButton, SIGNAL(clicked()), this, SLOT(runApp()));

    /* create render area */
}

MainWindow::~MainWindow()
{
    delete plotArea;
    delete ui;
}

void MainWindow::selectApp()
{
    const QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty())
    {
      ui->appName->setText(fileName);
      appNameString = fileName;
    }
}

void MainWindow::runApp()
{
    const bool isStethoscope = ui->stethoscope_checkBox->isChecked();
    if (appNameString.isEmpty() && !isStthoscope)
    {
        QMessageBox::critical(this, tr("Error"),
                              tr("No app is specified."));
        return;
    }

    /* run profiling */
    const bool isFlops    = ui->flops_checkBox   ->isChecked();
    const bool isFlopsSP  = ui->flopsSP_checkBox ->isChecked();
    const bool isFlopsDP  = ui->flopsDP_checkBox ->isChecked();
    const bool isFlopsAVX = ui->flopsAVX_checkBox->isChecked();
    const bool isBW       = ui->BW_checkBox      ->isChecked();
    const bool isL2       = ui->L2_checkBox      ->isChecked();

    const bool isChecked =
            isFlops |
            isFlopsSP |
            isFlopsDP |
            isFlopsAVX |
            isBW |
            isL2;

    if (!isChecked)
    {
        QMessageBox::critical(this, tr("likewid-fe"),
                              tr("Please check at least one of the profiling boxes"),
                              QMessageBox::Ok);
        return;
    }

    /* profile app */
}
