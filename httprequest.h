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
    QString contentType;
    unsigned int port;
    QHostAddress host, remoteAddress;
    QList<QNetworkCookie> cookieJar;

    QHash<QString, QVariant> fields;
    QHash<QString, QString> postData;
    QByteArray rawPostData;
};

#endif // HTTPREQUEST_H
