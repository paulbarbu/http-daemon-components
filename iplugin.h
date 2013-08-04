#ifndef IHTTPREQUESTHANDLERFACTORY_H
#define IHTTPREQUESTHANDLERFACTORY_H

#include "httprequesthandler.h"

class IPlugin
{
public:
    virtual ~IPlugin(){}
    virtual HTTPRequestHandler *getHTTPRequestHandler(const HTTPRequest &requestData)=0;
};

Q_DECLARE_INTERFACE(IPlugin, "http-daemon.IHTTPRequestHandlerFactory/1.0")
#endif // IHTTPREQUESTHANDLERFACTORY_H
