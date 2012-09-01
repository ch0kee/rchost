#ifndef LAMBDAFUNCTION_H
#define LAMBDAFUNCTION_H

#include <QObject>
#include <functional>

class lambdafunction
        : public QObject
{
    Q_OBJECT
public:

    typedef std::function<void(void)> function_t;

    lambdafunction(const function_t& func);

public slots:
    void    apply();

private:
    function_t _function;
};

#endif // LAMBDAFUNCTION_H
