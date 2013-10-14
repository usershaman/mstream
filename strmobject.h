#ifndef STRMOBJECT_H
#define STRMOBJECT_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QProcess>

class strmObject : public QObject
{
    Q_OBJECT
public:
    explicit strmObject(QObject *parent = 0);
    //void setup(QThread &sThread);

signals:
    void finished();

public slots:
    void doTask();

};

#endif // STRMOBJECT_H
