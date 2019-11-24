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

    Process_Message(data);

    outSocket("[" + clientSocket->peerAddress().toString() + "]: " + data);

    // Если нужно закрыть сокет
    clientSocket->close();

    qlonglong idusersocs = clientSocket->socketDescriptor();
    SockClients.remove(idusersocs);
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

bool TcpSocketReader::Process_Message(QString data)
{
    QString command_code = data.left(data.indexOf(' '));
    QString command_data = data.mid(data.indexOf( command_code )
                           + command_code.length() + 1, data.length());

    if(isDigitalOnly(command_code)){
        switch (command_code.toInt()) {
        case 3770:{
            gotSelfDescriptionNumber(command_data.toInt());
            return true;
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
            return true;
        }
        default:{
            qDebug() << "Uknown command!";
            return false;
        }
        }
    }

    return false;
}
//-------------------------------------------------------------------------------------//
