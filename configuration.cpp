#include "configuration.h"

#include <QtXml/QDomDocument>
#include <QFile>
#include <deque>
#include <functional>

#include <iostream>
configuration::configuration()
{
}


//c CSAK EGY SZINTU XML-RE MUXIK EGYELORE
bool configuration::load(const std::string &xml)
{
    QDomDocument doc("mydocument");
    QFile file(xml.c_str());
    if (!file.open(QIODevice::ReadOnly))
        return false;
    if (!doc.setContent(&file)) {
        file.close();
        return false;
    }
    file.close();

    QDomElement docElem = doc.documentElement();
    if ( docElem.tagName() != "rchost")
        return false;

    QDomNodeList docElemChildNodes = docElem.childNodes();
    for(int i = 0; i < docElemChildNodes.size(); ++i)
    {
        QDomElement e = docElemChildNodes.at(i).toElement();
        std::string prefix = e.tagName().toStdString();

        QDomNamedNodeMap attrs = e.attributes();
        for(int j = 0; j < attrs.size(); ++j)
        {
            std::string name = attrs.item(j).nodeName().toStdString();
            std::string value = attrs.item(j).nodeValue().toStdString();

            _dictionary[ prefix + "/" + name ] = value;
        }
    }
    return true;
}

std::string configuration::get_value(const std::string &key) const
{
    return _dictionary.at(key);
}
