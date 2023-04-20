#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    sWatch = new Stopwatch(this);
    connect(sWatch, &Stopwatch::sig_sendStart, this, [&]{
        ui->lb_time->setText(QString::number(sWatch->tPtr->remainingTime()));
    });
    connect(ui->pb_startStop, &QPushButton::clicked, this, &MainWindow::sendStart);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sendStart()
{
    emit sWatch->sig_sendStart();
}
