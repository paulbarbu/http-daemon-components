#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include <QHash>
#include <QUrl>
#include <QString>
#include <QVariant>
#include <QHostAddress>

struct HTTPRequest
{
    QString method;
    QUrl url;
    QString protocol;
    double protocolVersion;
    int contentLength;
    unsigned int port;
    QHostAddress host;

    QHash<QString, QVariant> fields;
    QHash<QString, QString> postData; //TODO: use QVariant instead of QStringList
};

#endif // HTTPREQUEST_H
