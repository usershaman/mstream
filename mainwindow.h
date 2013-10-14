#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QThread>
#include "strmobject.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void updateInfo();
    void on_vidBtn1_clicked();

    void on_streamBtn_clicked();

private:
    Ui::MainWindow *ui;
    short vidIndex;
//    QThread sThread;
//    strmObject sObject;

signals:
    void updatePane();

};

#endif // MAINWINDOW_H
