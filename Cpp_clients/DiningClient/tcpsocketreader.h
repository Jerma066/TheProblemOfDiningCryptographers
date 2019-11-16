#ifndef TCPSOCKEREADER_H
#define TCPSOCKEREADER_H

#include <QDebug>
#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QDateTime>

class TcpSocketReader: public QObject
{
    Q_OBJECT

public:
    explicit TcpSocketReader(QObject *parent = nullptr);
    ~TcpSocketReader();
    QTcpServer *thisServer;

public slots:
    void process_SocketReader();
    void NewUser();
    void ReadFromSocket();

signals:
    void finished_SocketReader();
    void outSocket(QString sended_data);

private:
    QByteArray data;
    bool server_status;
    QMap<qlonglong, QTcpSocket*> SockClients;

    //Атрибуты сервера
    QHostAddress host = QHostAddress::Any;
    quint16 port = 9191;

};

#endif // TCPSOCKEREADER_H
