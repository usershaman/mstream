#ifndef SRCHOBJECT_H
#define SRCHOBJECT_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QProcess>
#include <QStringList>

class srchObject : public QObject
{
    Q_OBJECT
public:
    explicit srchObject(QObject *parent = 0);

private:
    QString* term;

signals:
    void finished();

public slots:
    void doTask();
    void getQuery(QString *query);

};

#endif // SRCHOBJECT_H
