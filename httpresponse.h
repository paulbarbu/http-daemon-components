#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H

#include <QByteArray>
#include <QString>
#include <QHash>
#include <QMultiHash>
#include <QNetworkCookie>

class HTTPResponse
{
public:
    HTTPResponse();
    bool setStatusCode(unsigned int value); //TODO: replace with an enum

    void setReasonPhrase(const QString &value);
    void setReasonPhrase(const QByteArray &value);
    void setReasonPhrase(const char *value);

    void setBody(const QString &value);
    void setBody(const QByteArray &value);
    void setBody(const char *value);

    void appendBody(const QString &value);
    void appendBody(const QByteArray &value);
    void appendBody(const char *value);

    void setHeaderField(const QString &key, const QString &value);
    void addHeaderFields(const QHash<QString, QString> &value);

    void setCookie(const QNetworkCookie &cookie);

    QByteArray get() const;
    QByteArray getPartial();

private:
    QByteArray body;
    QByteArray reasonPhrase;
    QByteArray statusCode;
    QMultiHash<QByteArray, QByteArray> fields;
    //TODO: maybe use QVariant here

    bool isValidStatusCode(unsigned int value) const;
};

#endif // HTTPRESPONSE_H
