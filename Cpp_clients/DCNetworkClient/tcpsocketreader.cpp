#include "tcpsocketreader.h"

TcpSocketReader::TcpSocketReader(QObject *parent):QObject(parent)
{

}

TcpSocketReader::~TcpSocketReader()
{
    qDebug() << "TcpSocketReader: Bye in Thread!";
    emit finished_SocketReader();
}

//метод run класса TcpSocketReader
void TcpSocketReader::process_SocketReader()
{
    qDebug() << "TcpSocketReader: Start working in Thread";

    thisServer = new QTcpServer(this);
    connect(thisServer, SIGNAL(newConnection()), this, SLOT(NewUser()));
    if (!thisServer->listen(host, port) && server_status == 0) {
        qDebug() <<  QObject::tr("Unable to start the server: %1.").arg(thisServer->errorString());
    } else {
        server_status = true;
        qDebug() << "TCP_Socket listen on port:" << thisServer->isListening();
        qDebug() << "Server is running";
    }

}

//метод Конвертирования
QString TcpSocketReader::ConvertFromIPv6ToIpv4(QHostAddress address)
{
    bool conversionOK = false;
    QHostAddress ip4Address(address.toIPv4Address(&conversionOK));
    QString ip4String;
    if (conversionOK)
    {
        ip4String = ip4Address.toString();
    }

    return ip4String;
}

void TcpSocketReader::NewUser()
{
    if(server_status == 1){
        QTcpSocket* clientSocket=thisServer->nextPendingConnection();

        //Аргумет - ключ словаря по которому будет лежать дескриптор сокета клиента
        qlonglong idusersocs = clientSocket->socketDescriptor();

        //Заполнение словаря дескрипторов сокетов
        SockClients[idusersocs] = clientSocket;

        //Обрабатываем сигнал readyRead
        connect(SockClients[idusersocs], SIGNAL(readyRead()), this, SLOT(ReadFromSocket()));
    }
}

//Слот чтения данных из сокета по сигналу readyRead
void TcpSocketReader::ReadFromSocket()
{
    QTcpSocket* clientSocket = static_cast<QTcpSocket*>(sender());
    QTextStream os(clientSocket);

    data = clientSocket->readAll();
    currentSenderIPv4Addr = ConvertFromIPv6ToIpv4(clientSocket->peerAddress());

    Process_Message(data);
    outSocket("[" + currentSenderIPv4Addr + "] >> " + data);

    clientSocket->close();

    qlonglong idusersocs = clientSocket->socketDescriptor();
    SockClients.remove(idusersocs);
}

void TcpSocketReader::SetConnectionParameters(QPair<QString, quint16> selfSettings,
                                              QPair<QString, quint16> serverSettings)
{
    serverSocket = serverSettings;
}

//-------------------------Обработка входящий сообщений--------------------------------//
//-------------------------------------------------------------------------------------//
bool isDigitalOnly(QString str)
{
    foreach(QChar c, str)
    {
        if(c < '0' || c > '9')
            return false;
    }

    return true;
}

bool TcpSocketReader::isInAddressesMap(QString current_addres){
    for(auto it = adresses_descriptions.begin(); it != adresses_descriptions.end(); it++){
        if (current_addres == *it) {
            return true;
        }
    }

    if(current_addres == serverSocket.first){
        return true;
    }

    return false;
}

void TcpSocketReader::Process_Message(QString data)
{
    if(isInAddressesMap(currentSenderIPv4Addr)) {
        QString command_code = data.left(data.indexOf(' '));
        QString command_data = data.mid(data.indexOf( command_code )
                               + command_code.length() + 1, data.length());

        if(isDigitalOnly(command_code)){
            switch (command_code.toInt()) {
            case 3770:{
                if(isDigitalOnly(command_data) && command_data.toInt() > 0
                                               && command_data.toInt() < adresses_descriptions.size()){
                    gotSelfDescriptionNumber(command_data.toInt());
                }
                break;
            }
            case 3772:{
                if(isDigitalOnly(command_data) && command_data.toInt() > 0
                                               && command_data.toInt() < adresses_descriptions.size()){
                    gotSelfBroadcastNumber(command_data.toInt());
                    qDebug() << "Broadcast position = " << command_data.toInt();
                }
                break;
            }
            case 3773:{
                if(isDigitalOnly(command_data) && command_data.toInt() > 0
                                               && command_data.toInt() < adresses_descriptions.size()){
                    gotNumberOfMessages(command_data.toInt());
                    qDebug() << "The number of messages = " << command_data.toInt();
                }
                break;
            }
            case 3771:{
                QMap<int, QString> users_addresses;

                int num_of_items = command_data.count(':');
                for (int i = 0; i < num_of_items; i++){
                    //вычисление позиций необходимых для парсинга
                    int i_addr_from = command_data.indexOf('\'');
                    command_data[i_addr_from] = '*';
                    int i_addr_to = command_data.indexOf('\'');
                    int i_desc_from = i_addr_to + 2;
                    command_data[i_addr_to] = '*';
                    int i_desc_to;
                    if(i != num_of_items - 1){
                        i_desc_to = command_data.indexOf(',');
                        command_data[i_desc_to] = '*';
                    }
                    else{
                        i_desc_to = command_data.indexOf('}');
                    }

                    QString address = command_data.mid(i_addr_from + 1,
                                                       i_addr_to - i_addr_from - 1);
                    QString descriptor = command_data.mid(i_desc_from + 1,
                                                          i_desc_to - i_desc_from - 1);

                    adresses_descriptions[address] = descriptor.toInt();
                    users_addresses[descriptor.toInt()] = address;
                }

                gotDescriptionsOfGuests(users_addresses);
                break;
            }
            case 3140:{
                if(isDigitalOnly(command_data) && (command_data.toInt() == 0 || command_data.toInt() == 1)){
                    int obtained_secret = command_data.toInt();
                    gotSideSecret(obtained_secret);
                }
                break;
            }
            case 3141:{
                if(isDigitalOnly(command_data) && (command_data.toInt() == 0 || command_data.toInt() == 1)){
                    int side_xor_result = command_data.toInt();
                    gotSideXorResult(side_xor_result);
                }
                break;
            }
            case 3142:{
                if(isDigitalOnly(command_data) && (command_data.toInt() == 0 || command_data.toInt() == 1)){
                    int result = command_data.toInt();
                    gotSideProtocolAnswer(result);
                }
                break;
            }
            default:{
                qDebug() << "Uknown command code!";
                break;
            }
            }
        }
    }
}
//-------------------------------------------------------------------------------------//
