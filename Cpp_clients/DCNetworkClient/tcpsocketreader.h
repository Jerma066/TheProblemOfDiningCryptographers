#ifndef TCPSOCKEREADER_H
#define TCPSOCKEREADER_H

#include <QDebug>
#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QDateTime>

#include "generic.h"

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
    void Process_Message(QString data);
    void SetConnectionParameters(QPair<QString, quint16>, QPair<QString, quint16>);
    QString ConvertFromIPv6ToIpv4(QHostAddress address);

private:
    bool isInAddressesMap(QString);

signals:
    void finished_SocketReader();
    void outSocket(QString sended_data);
    void gotSelfDescriptionNumber(int number);
    void gotSelfBroadcastNumber(int number);
    void gotNumberOfMessages(int number);
    void gotDescriptionsOfGuests(QMap<int, QString>);
    void gotSideXorResult(int value);
    void gotSideSecret(int value);
    void gotSideProtocolAnswer(int);


private:
    QByteArray data;
    bool server_status;
    QMap<qlonglong, QTcpSocket*> SockClients;
    QPair<QString, quint16> serverSocket;

    //Атрибуты сервера
    QHostAddress host = QHostAddress::Any;
    quint16 port = DEFAULT_SELF_PORT;
    bool clientHaveNumber = false;
    QMap<QString, int> adresses_descriptions;
    QString currentSenderIPv4Addr;
};

#endif // TCPSOCKEREADER_H
