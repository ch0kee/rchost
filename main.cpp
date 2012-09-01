#include <QtCore/QCoreApplication>
#include <application.h>
#include <server.h>
#include <configuration.h>
#include <iostream>
#include <string>
#include <boost/thread.hpp>



int main(int argc, char *argv[])
{
    QCoreApplication coreApp(argc, argv);
    try {
        configuration config;
        config.load("rchost.xml");


        server srv;
        application app;

        srv.configure_port(config);
        app.configure_executable(config);

        QObject::connect(&srv, SIGNAL(client_connected()),
                         &app, SLOT(kill_application()));
        boost::thread tcpthread(&server::listener, &srv);

        std::cout << "executing.." << std::endl;
        app.execute();

        coreApp.exec();

        app.terminate();

        tcpthread.join();
        std::cout << "terminated." << std::endl;
    }
                 catch(...)
    {
                 std::cout << "whoops";
    }

}
