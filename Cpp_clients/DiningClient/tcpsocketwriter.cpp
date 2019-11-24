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

    connectToUser(host, port);
    forwarding_state = writeData(data);
    disconnecFromUser();
    disconnect_state = (socket->state() == QAbstractSocket::UnconnectedState);

    if(forwarding_state & disconnect_state){
        exportData(data);
    }
    else if(!forwarding_state){
        exportData("[ERROR: ] -faied to send data: <<" + data + ">>");
    }
    else if(!disconnect_state){
        exportData(data + "\n" + "[ERROR: ] -failed to disconnect from socket");
    }


    return (forwarding_state & disconnect_state);
}

void TcpSocketWriter::SetConnectionParameters(QPair<QString, quint16> selfSettings,
                                              QPair<QString, quint16> serverSettings)
{
    serverSocket = serverSettings;
}

void TcpSocketWriter::CaughtSelfDescriptionNumber(int number)
{
    haveNumber = true;
    selfDescriptionNumber = number;
}

void TcpSocketWriter::CaughtDescriptionsOfGuests(QMap<int, QString> users_descriptions)
{
    haveAddressesMap = true;
    descriptors_adresses = users_descriptions;
}

void TcpSocketWriter::GetNumber()
{
    auto host = serverSocket.first;
    auto port = serverSocket.second;

    while(!haveNumber){
        connectToUser(host, port);

        writeData(GETTING_NUMBER_STR);
        exportData(GETTING_NUMBER_STR);

        QGuiApplication::processEvents();
        disconnecFromUser();

        delay(50);
    }
}

//-----------------Временной интервал--------------------------------------//
//-------------------------------------------------------------------------//
void TcpSocketWriter::delay(int millisecondsToWait)
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}
//-------------------------------------------------------------------------//
