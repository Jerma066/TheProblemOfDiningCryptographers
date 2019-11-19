#include "tcpsocketwriter.h"

TcpSocketWriter::TcpSocketWriter(QObject *parent):QObject(parent)
{

}


TcpSocketWriter::~TcpSocketWriter()
{
    qDebug() << "TcpSocketWriter: Bye in Thread!";
    emit finished_SocketWriter();
}

void TcpSocketWriter::process_SocketReader()
{
    qDebug() << "TcpSocketWriter: Start working in Thread";
    socket = new QTcpSocket(this);


    writeDataToUser(LOOP_BACK_ADDRESS, DEFAULT_PORT, "Hey! Bro, what is my number?");         //Проверка
}

bool TcpSocketWriter::connectToUser(QString host, quint16 port)
{
    socket->connectToHost(host, port);
    return socket->waitForConnected();
}

void TcpSocketWriter::disconnecFromUser()
{
    socket->disconnectFromHost();
}

bool TcpSocketWriter::writeData(QByteArray data)
{
    if(socket->state() == QAbstractSocket::ConnectedState)
    {
        socket->write(data);                        // Запись самых данных непосредственно
        return socket->waitForBytesWritten();
    }
    else
        return false;
}

bool TcpSocketWriter::writeDataToUser(QString host, quint16 port, QByteArray data)
{
    bool forwarding_state, disconnect_state;

    this->connectToUser(host, port);
    forwarding_state = this->writeData(data);
    this->disconnecFromUser();
    disconnect_state = (socket->state() == QAbstractSocket::UnconnectedState);

    return (forwarding_state & disconnect_state);
}

