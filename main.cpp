#include <QCoreApplication>
#include <QThread>
#include <QDebug>

#include "client.h"
#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // create server

    QThread serverThread;
    serverThread.start();

    Server *server = new Server();
    server->moveToThread(&serverThread);

    QMetaObject::invokeMethod(server, "prepare", Qt::BlockingQueuedConnection);


    // create client

    QThread clientThread;
    clientThread.start();

    Client *client = new Client();
    client->moveToThread(&clientThread);
    QMetaObject::invokeMethod(client, "openSocket", Qt::BlockingQueuedConnection);



    return a.exec();
}
