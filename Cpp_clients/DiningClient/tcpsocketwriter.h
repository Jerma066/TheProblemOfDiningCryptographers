#ifndef TCPSOCKETWRITER_H
#define TCPSOCKETWRITER_H

#include <QDebug>
#include <QObject>
#include <QTcpSocket>
#include <QDateTime>
#include <QDataStream>

#include "generic.h"

class TcpSocketWriter: public QObject
{
    Q_OBJECT

public:
     explicit TcpSocketWriter(QObject *parent = nullptr);
    ~TcpSocketWriter();

signals:
    void finished_SocketWriter();

public slots:
    void process_SocketReader();
    bool writeDataToUser(QString host, quint16 port, QByteArray data);

private slots:
    bool connectToUser(QString host, quint16 port);
    void disconnecFromUser();
    bool writeData(QByteArray data);

private:
    QTcpSocket *socket;

};

#endif // TCPSOCKETWRITER_H
