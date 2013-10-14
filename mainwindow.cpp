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

    // creating the GUI here, widgets and layouts

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
    // Threading for the stream, uses QObject and moves it to a QThread
    QThread* sThread = new QThread;
    strmObject* sObject = new strmObject();

    sObject->moveToThread(sThread);
    connect(sThread, SIGNAL(started()), sObject, SLOT(doTask()));
    connect(sObject, SIGNAL(finished()), sObject, SLOT(deleteLater()));
    connect(sThread, SIGNAL(finished()), sThread, SLOT(deleteLater()));
    sThread->start();
}

void MainWindow::on_lineEdit_returnPressed()
{
    // Threading for the search, uses QObject and moves it to a QThread
    QThread* srThread = new QThread;
    srchObject* srObject = new srchObject();

    srObject->moveToThread(srThread);
    connect(this, SIGNAL(startSearch(QString*)), srObject, SLOT(getQuery(QString*)));
    //connect(srThread, SIGNAL(started()), srObject, SLOT(doTask()));
    connect(srObject, SIGNAL(finished()), srObject, SLOT(deleteLater()));
    connect(srThread, SIGNAL(finished()), srThread, SLOT(deleteLater()));
    connect(srObject, SIGNAL(finished()), this, SLOT(parseData()));

    QString* name = new QString();
    *name = QString(ui->lineEdit->text());
    emit startSearch(name);

    srThread->start();
}

void MainWindow::parseData()
{
    QFile file("result");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        qDebug() << line;
    }

    file.close();
}
