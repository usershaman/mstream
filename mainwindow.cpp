#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget *window = new QWidget();
    QGridLayout *gLayout = new QGridLayout;
    QHBoxLayout *hLayout = new QHBoxLayout;
    QHBoxLayout *vLayout = new QHBoxLayout;

    gLayout->addWidget(ui->titleBig, 0, 0, 1, 1);
    gLayout->addWidget(ui->thumbBig, 2, 0, 1, 1);
    gLayout->addWidget(ui->info, 1, 0, 1, 1);
    gLayout->addWidget(ui->streamBtn, 3, 0, 2, 2);
    hLayout->addLayout(gLayout);
    vLayout->addWidget(ui->scrollArea);
    vLayout->addSpacing(50);
    vLayout->addLayout(hLayout);
    vLayout->addSpacing(50);

    window->setLayout(vLayout);

    setCentralWidget(window);

    vidIndex = 0;
    connect(this, SIGNAL(updatePane()), this, SLOT(updateInfo()));

    streamThread = new stmThread(this);
    connect(this, SIGNAL(sigStream(QProcess*)), streamThread, SLOT(streamSlot(QProcess*)));

    proc = new QProcess(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateInfo()
{
    ui->titleBig->setText("The button worked");
}

void MainWindow::on_vidBtn1_clicked()
{
    this->vidIndex = 1;
    emit updatePane();
}

void MainWindow::on_streamBtn_clicked()
{
    //start stream now
    emit sigStream(proc);
    streamThread->start();
}
