#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include <QHash>
#include <QUrl>
#include <QString>
#include <QVariant>
#include <QHostAddress>
#include <QNetworkCookie>

struct HTTPRequest
{
    QString method;
    QUrl url;
    QString protocol;
    double protocolVersion;
    int contentLength;
    unsigned int port;
    QHostAddress host, remoteAddress;
    QList<QNetworkCookie> cookieJar;

    QHash<QString, QVariant> fields;
    QHash<QString, QString> postData;
};

#endif // HTTPREQUEST_H
