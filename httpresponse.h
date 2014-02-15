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
    QByteArray getStatusCode() const;

    void setReasonPhrase(const QString &value);
    void setReasonPhrase(const QByteArray &value);
    void setReasonPhrase(const char *value);
    QByteArray getReasonPhrase() const;

    void setBody(const QString &value);
    void setBody(const QByteArray &value);
    void setBody(const char *value);
    QByteArray getBody() const;

    void appendBody(const QString &value);
    void appendBody(const QByteArray &value);
    void appendBody(const char *value);

    void setHeaderField(const QString &key, const QString &value);
    void addHeaderFields(const QHash<QString, QString> &value);
    QMultiHash<QByteArray, QByteArray> getFields() const;

    void setCookie(const QNetworkCookie &cookie);

    QByteArray get() const;
    QByteArray getPartial();

    bool isValidStatusCode(unsigned int value) const;
    void clear();

private:
    QByteArray body;
    QByteArray reasonPhrase;
    QByteArray statusCode;
    QMultiHash<QByteArray, QByteArray> fields;
    //TODO: maybe instead of a QMultiHash it's better to revert to a QHash
    //and store cookies in a separate QList in order to allow removal too
    //and only add them to the header when get() is called
};

#endif // HTTPRESPONSE_H
