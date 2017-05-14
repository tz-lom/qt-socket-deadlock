#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);

    QTcpServer *server;
signals:

public slots:

    void prepare();
    void clientConnected();
};

#endif // SERVER_H
