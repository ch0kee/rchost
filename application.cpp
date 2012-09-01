#include "application.h"

#include <configuration.h>
#include <QDir>
#include <chrono>
#include <thread>
#include <boost/scope_exit.hpp>


void application::configure_executable(const configuration& conf)
{
    _dir = conf.get_value("application/directory");
    _exe = conf.get_value("application/executable");
}

void application::execute()
{

    QString original_current_path = QDir::currentPath();
    BOOST_SCOPE_EXIT(original_current_path) {
        QDir::setCurrent(original_current_path);
    } BOOST_SCOPE_EXIT_END

    QDir::setCurrent(_dir.c_str());
    _process.setWorkingDirectory(_dir.c_str());
    _process.start(_exe.c_str());
    _process.waitForStarted();
}

void application::kill_application()
{
    std::cout << "terminating" << std::endl;
    terminate();
}

void application::terminate()
{
    _process.kill();
    _process.waitForFinished();
}


