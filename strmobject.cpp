#include "strmobject.h"

strmObject::strmObject(QObject *parent) :
    QObject(parent)
{
}

//void strmObject::setup(QThread &sThread)
//{
//    connect(&sThread, SIGNAL(started()), this, SLOT(doTask()));
//}

void strmObject::doTask()
{
    QProcess *proc = new QProcess(this);
    proc->start("glxgears");
    proc->waitForFinished();
    emit finished();
}
