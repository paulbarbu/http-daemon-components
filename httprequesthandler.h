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
    HTTPRequestHandler(){}
    HTTPRequestHandler(const QHash<QString, QVariant> &s, QObject *parent=0) :
        QObject(parent), settings(s) {}

    virtual ~HTTPRequestHandler() {}
    virtual void createResponse(const HTTPRequest &r)=0;

protected:
    const QHash<QString, QVariant> settings;

signals:
    void responseWritten(HTTPResponse response);
    void rawDataWritten(uchar *data, int size);
    void endOfWriting();
};

#endif // HTTPREQUESTHANDLER_H
