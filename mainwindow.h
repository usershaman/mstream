#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QThread>
#include <QFile>
#include <QMessageBox>
#include "strmobject.h"
#include "srchobject.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void parseData();

private slots:
    void updateInfo();

    void on_vidBtn1_clicked();
    void on_streamBtn_clicked();
    void on_lineEdit_returnPressed();

private:
    Ui::MainWindow *ui;
    short vidIndex;
//    QThread sThread;
//    strmObject sObject;

signals:
    void updatePane();
    void startSearch(QString* query);

};

#endif // MAINWINDOW_H
