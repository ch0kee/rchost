#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <boost/asio.hpp>
#include <boost/thread.hpp>

class configuration;
class session;
class server
        : public QObject
{
    Q_OBJECT
public:
    server();
    void configure_port(const configuration& conf);
    void start();
    void stop();
    void    listener();
signals:
    void client_connected();
private:
    void    handle_accept(session* s);
    unsigned short int _port;
    boost::asio::io_service _io_service;
};

#endif // SERVER_H
