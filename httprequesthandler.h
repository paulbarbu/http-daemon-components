#ifndef HTTPREQUESTHANDLER_H
#define HTTPREQUESTHANDLER_H

#include <QObject>

#include "httprequest.h"
#include "httpresponse.h"

/* TODO: https://qt-project.org/doc/qt-4.8/plugins-howto.html
 * says that I shoudl have only pure virtual functions, is it ok not to?
 */

/*TODO: the interface of the plugin should declare how the plugin returns a
 *HTTPRequestHandler, so IPlugin would help me pass a HTTPRequest to
 *HTTPRequestHandler, which will be returned
 */

class HTTPRequestHandler : public QObject
{
    Q_OBJECT
public:
    HTTPRequestHandler(const HTTPRequest &r) : requestData(r) {}
    virtual ~HTTPRequestHandler() {}
    virtual void createResponse()=0;/*
    void setRequestData(const HTTPRequest &r){
        requestData = r;
    }*/

protected:
    HTTPRequest requestData;

signals:
    void responseWritten(HTTPResponse &response);
    void endOfWriting();
};

#endif // HTTPREQUESTHANDLER_H
