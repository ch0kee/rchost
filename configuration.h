#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QString>
#include <string>
#include <map>
#include <set>

class configuration
{
public:
    configuration();

    bool    load(const std::string& xml);
    std::string get_value(const std::string& key) const;
private:
    std::map< std::string, std::string > _dictionary;
};

#endif // CONFIGURATION_H
