#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QDebug>
#include <QTcpSocket>
#include <QThread>
#include <QEventLoop>
#include <QCoreApplication>

class Client: public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);

    QTcpSocket *socket;

    void readFromSocket(std::size_t size, char *memory);

signals:
public slots:

    void openSocket();

};

#endif // CLIENT_H
