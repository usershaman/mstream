#ifndef STMTHREAD_H
#define STMTHREAD_H

#include <QThread>
#include <QDebug>
#include <QProcess>

class stmThread : public QThread
{
    Q_OBJECT
public:
    explicit stmThread(QObject *parent = 0);
    void run();

signals:

public slots:
    void streamSlot(QProcess *proc);

private:
    QProcess *pross;

};

#endif // STMTHREAD_H
