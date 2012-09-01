#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
#include <QProcess>
#include <QObject>

class configuration;
class application
        : public QObject
{
    Q_OBJECT
public:
    void    configure_executable(const configuration& conf);
    void    execute();
    void    terminate();
public slots:
    void    kill_application();
private:
    std::string _dir;
    std::string _exe;

    QProcess _process;
};


#endif // APPLICATION_H
