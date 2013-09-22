#include "stmthread.h"
#include <QProcess>

stmThread::stmThread(QObject *parent) :
    QThread(parent)
{
}

void stmThread::run()
{
    qDebug() << "run start";
    pross->start("./glx");
    pross->waitForFinished();
}

void stmThread::streamSlot(QProcess *proc)
{
    //this->run(proc);
    pross = new QProcess(this);
    pross = proc;
}
