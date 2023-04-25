#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pb_loop->setEnabled(false);

    sWatch = new Stopwatch(this);
    connect(sWatch, &Stopwatch::timeoutSignal, this, [&]{
        ui->lb_time->setText(sWatch->getTime());
    });
    connect(ui->pb_startStop, &QPushButton::clicked, this, &MainWindow::getStartStop);
    connect(ui->pb_loop, &QPushButton::clicked, this, [&]{
        ui->tb_info->append("Круг " + sWatch->getLoop() + ", время: " + sWatch->getLoopTime() + " сек");
    });
    connect(ui->pb_clear, &QPushButton::clicked, this, [&]{
        sWatch->clear();
        ui->lb_time->setText("0.0");
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getStartStop()
{
    if(!sWatch->isStarted())
    {
        sWatch->startTimer();
        ui->pb_startStop->setText("Стоп");
        ui->pb_loop->setEnabled(true);
    }
    else
    {
        sWatch->stopTimer();
        ui->pb_startStop->setText("Старт");
        ui->pb_loop->setEnabled(false);
    }
}
