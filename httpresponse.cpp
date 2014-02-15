#include <QDebug>

#include "httpresponse.h"

HTTPResponse::HTTPResponse() : statusCode(0)
{
}

bool HTTPResponse::setStatusCode(unsigned int value)
{
    if(!isValidStatusCode(value)){
        return false;
    }

    statusCode = QByteArray::number(value);

    return true;
}

QByteArray HTTPResponse::getStatusCode() const
{
    return statusCode;
}

void HTTPResponse::setBody(const QString &value)
{
    body = value.toUtf8();
}

void HTTPResponse::setBody(const char *value)
{
    body = value;
}

QByteArray HTTPResponse::getBody() const
{
    return body;
}

void HTTPResponse::appendBody(const QString &value)
{
    body += value;
}

void HTTPResponse::appendBody(const QByteArray &value)
{
    body += value;
}

void HTTPResponse::appendBody(const char *value)
{
    body += value;
}

void HTTPResponse::setBody(const QByteArray &value)
{
    body = value;
}

QByteArray HTTPResponse::get() const
{
    //TODO: memoize the response until a set*() method is called

    if("" == statusCode || "" == reasonPhrase){
        return "";
    }

    QByteArray response = "HTTP/1.0 " + statusCode + " " + reasonPhrase + "\r\n";

    QMultiHash<QByteArray, QByteArray>::const_iterator i;
    for(i = fields.constBegin(); i != fields.constEnd(); ++i){
        response += i.key() + ": " + i.value() + "\r\n";
    }

    response += "\r\n" + body;

    return response;
}

QByteArray HTTPResponse::getPartial()
{
    QByteArray response = get();

    if("" == response){
        response += body;
    }
    else{
        statusCode = 0;
        reasonPhrase = "";
    }

    body = "";

    return response;
}

bool HTTPResponse::isValidStatusCode(unsigned int value) const
{
    int firstDigit = value / 100;
    if(firstDigit >= 1 && firstDigit <= 5){
        return true;
    }

    return false;
}

void HTTPResponse::clear()
{
    reasonPhrase.clear();
    body.clear();
    statusCode.clear();
    fields.clear();
}

void HTTPResponse::setReasonPhrase(const QString &value)
{
    reasonPhrase = value.toUtf8();
}

void HTTPResponse::setReasonPhrase(const char *value)
{
    reasonPhrase = value;
}

QByteArray HTTPResponse::getReasonPhrase() const
{
    return reasonPhrase;
}

void HTTPResponse::setHeaderField(const QString &key, const QString &value)
{
    fields.insert(key.toUtf8(), value.toUtf8());
}

void HTTPResponse::addHeaderFields(const QHash<QString, QString> &value)
{
    QHash<QString, QString>::const_iterator i;

    for(i = value.constBegin(); i != value.constEnd(); ++i){
        setHeaderField(i.key(), i.value());
    }
}

QMultiHash<QByteArray, QByteArray> HTTPResponse::getFields() const
{
    return fields;
}

void HTTPResponse::setCookie(const QNetworkCookie &cookie)
{
    setHeaderField("Set-Cookie", cookie.toRawForm());
}

void HTTPResponse::setReasonPhrase(const QByteArray &value)
{
    reasonPhrase = value;
}
