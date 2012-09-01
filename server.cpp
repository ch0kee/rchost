#include "server.h"
#include <configuration.h>

#include <boost/lexical_cast.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>


using namespace boost::asio::ip;

///

class session
{
public:
    session(boost::asio::io_service& io_service)
        : _socket(io_service)
    {}
    tcp::socket& socket() { return _socket; }
private:
    tcp::socket _socket;
};




void server::handle_accept(session* s)
{
    std::cout << "client connected" << std::endl;
    emit client_connected();
}

void server::listener()
{
    boost::asio::ip::tcp::acceptor acceptor(_io_service,
                                            tcp::endpoint( tcp::v4(), _port));
    session* s = new session(_io_service);
    auto handler = boost::bind(&server::handle_accept, this, s);

    acceptor.async_accept(s->socket(), handler);
    std::cout << "accepting.." << std::endl;
    _io_service.run();
    std::cout << "not accepting." << std::endl;
}

server::server()
    : _port(65535)
{
    //    _io_service.run();
}

void server::configure_port(const configuration &conf)
{
    _port = boost::lexical_cast<unsigned short int>(conf.get_value("server/port"));
}


