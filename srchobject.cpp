#include "srchobject.h"

srchObject::srchObject(QObject *parent) :
    QObject(parent)
{
}

void srchObject::doTask()
{
    QProcess *proc = new QProcess(this);
    QStringList args;
    args << *term;
    proc->start("./search", args);
    proc->waitForFinished();
    qDebug("done");
    emit finished();
}

void srchObject::getQuery(QString *query)
{
    term = query;
    doTask();
}
