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

void TcpSocketWriter::ChangeStateOfBroacasting(bool state)
{
    stateOfBroadcasting = state;
    qDebug() << "state of broadcasting is " << state;
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

bool TcpSocketWriter::writeDataToUser(QString host, quint16 port, QString data)
{
    bool forwarding_state, disconnect_state;

    connectToUser(host, port);
    forwarding_state = writeData(data.toLocal8Bit());
    disconnecFromUser();
    disconnect_state = (socket->state() == QAbstractSocket::UnconnectedState);

    if(forwarding_state & disconnect_state){
        QString out_message = '[' + host + "] << " + data;
        exportData(out_message);
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

//Получение номера за столом;
void TcpSocketWriter::CaughtSelfDescriptionNumber(int number)
{
    haveNumbers = true;
    selfDescriptionNumber = number;
}

//Получение ноемера - порядка вещания;
void TcpSocketWriter::CaughtSelfBroadcastNumber(int number)
{
    haveBroadcastNumber = true;
    broadecastingNumber = number;
}

//Получение карты адрессов;
void TcpSocketWriter::CaughtDescriptionsOfGuests(QMap<int, QString> users_descriptions)
{
    haveAddressesMap = true;
    descriptors_adresses = users_descriptions;
}

void TcpSocketWriter::GetNumbers()
{
    auto host = serverSocket.first;
    auto port = serverSocket.second;

    while(!haveNumbers){
        connectToUser(host, port);

        if(stateOfBroadcasting){
            writeData(GETTING_NUMBER_AND_BRNUM_STR);
            exportData(GETTING_NUMBER_AND_BRNUM_STR);
        }
        else{
            writeData(GETTING_NUMBER_STR);
            exportData(GETTING_NUMBER_STR);
        }

        QGuiApplication::processEvents();
        disconnecFromUser();

        delay(150);
    }
}

void TcpSocketWriter::ProcessWritingMessage(QString message)
{
    QString command_code = message.left(message.indexOf(' '));

    switch (command_code.toInt()) {
    case 3141:{
        BroadcastMessage(message);
    }
    }
}

void TcpSocketWriter::SecretsFrindlyBroadcast(QVector<int> secrets)
{
    for (int i = selfDescriptionNumber + 1; i < descriptors_adresses.size(); i++) {
        QString current_receiver_host = descriptors_adresses[i];
        QString secret_data = "3140 " + QString::number(secrets[i - (selfDescriptionNumber + 1)]);
        writeDataToUser(current_receiver_host, DEFAULT_SELF_PORT, secret_data);
    }
}

void TcpSocketWriter::ProtocolAnswerBroadcastMessage(int answer)
{
    QString message = "3142 " + QString::number(answer);
    BroadcastMessage(message);
}

void TcpSocketWriter::BroadcastMessage(QString message)
{
    for(auto it = descriptors_adresses.begin(); it!=descriptors_adresses.end(); it++){
        QString host = it.value();
        if(host != descriptors_adresses[selfDescriptionNumber]){
            writeDataToUser(host, DEFAULT_SELF_PORT, message);
        }
    }
}




//-----------------Временной интервал--------------------------------------//
void TcpSocketWriter::delay(int millisecondsToWait)
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}
//-------------------------------------------------------------------------//
