#include "server.h"

Server::Server(QObject *parent) : QObject(parent)
{

}

void Server::prepare()
{
    server = new QTcpServer(this);

    server->listen(QHostAddress::AnyIPv4, 1337);

    if(!server->isListening())
    {
        qDebug() << "Server failed to listen";
    }

    connect(server, SIGNAL(newConnection()), this , SLOT(clientConnected()));

    qDebug() << "Server is ready";
}

void Server::clientConnected()
{
    qDebug() << "Server received Client";
    while(QTcpSocket *client = server->nextPendingConnection())
    {
        QByteArray ba("Hello world");
        qDebug() << "Server sended bytes" << client->write(ba);
        client->flush();
    }
}
