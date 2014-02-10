#ifndef HTTPREQUESTHANDLER_H
#define HTTPREQUESTHANDLER_H

#include <QObject>
#include <QHash>
#include <QString>
#include <QVariant>

#include "httprequest.h"
#include "httpresponse.h"

/* TODO: https://qt-project.org/doc/qt-4.8/plugins-howto.html
 * says that I should have only pure virtual functions, is it ok not to?
 */

class HTTPRequestHandler : public QObject
{
    Q_OBJECT
public:
    HTTPRequestHandler(const HTTPRequest &r, QObject *parent=0) :
        QObject(parent), requestData(r) {}
    HTTPRequestHandler(const HTTPRequest &r, const QHash<QString, QVariant> &s, QObject *parent=0) :
        QObject(parent), requestData(r), settings(s) {}

    virtual ~HTTPRequestHandler() {}
    virtual void createResponse()=0;
    /*
    void setRequestData(const HTTPRequest &r){
        requestData = r;
    }*/

protected:
    HTTPRequest requestData;
    const QHash<QString, QVariant> settings;

signals:
    void responseWritten(HTTPResponse &response);
    void endOfWriting();
};

#endif // HTTPREQUESTHANDLER_H
