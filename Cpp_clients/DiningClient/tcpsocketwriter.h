#ifndef TCPSOCKETWRITER_H
#define TCPSOCKETWRITER_H

#include <QObject>
#include <QTcpSocket>
#include <QDateTime>
#include <QDataStream>
#include <QGuiApplication>
#include <QTime>

#include "generic.h"

class TcpSocketWriter: public QObject
{
    Q_OBJECT

public:
     explicit TcpSocketWriter(QObject *parent = nullptr);
    ~TcpSocketWriter();

signals:
    void finished_SocketWriter();
    void exportData(QString sended_data);

public slots:
    void process_SocketReader();
    bool writeDataToUser(QString host, quint16 port, QString data);
    void SetConnectionParameters(QPair<QString, quint16> selfSettings, QPair<QString, quint16> serverSettings);
    void CaughtSelfDescriptionNumber(int);
    void CaughtDescriptionsOfGuests(QMap<int, QString> users_descriptions);
    void ProcessWritingMessage(QString message);

private slots:
    bool connectToUser(QString host, quint16 port);
    void disconnecFromUser();
    bool writeData(QByteArray data);
    void GetNumber();
    void SecretsFrindlyBroadcast(QVector<int> secrets);
    void BroadcastMessage(QString message);

public:
    void delay(int millisecondsToWait);

private:
    QTcpSocket *socket;
    bool haveNumber = false;
    bool haveAddressesMap = false;
    int selfDescriptionNumber;
    QPair<QString, quint16> serverSocket;
    QMap<int, QString> descriptors_adresses;

};

#endif // TCPSOCKETWRITER_H
