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
    if (!thisServer->listen(host, port) && server_status==0) {
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

    data = "ReadClient: "+clientSocket->readAll();
    outSocket(data);

    // Если нужно закрыть сокет
    clientSocket->close();

    qlonglong idusersocs = clientSocket->socketDescriptor();
    SockClients.remove(idusersocs);
}


