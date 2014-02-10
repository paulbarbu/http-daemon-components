#ifndef IHTTPREQUESTHANDLERFACTORY_H
#define IHTTPREQUESTHANDLERFACTORY_H

#include "httprequesthandler.h"

class IPlugin
{
public:
    virtual ~IPlugin(){}
    virtual HTTPRequestHandler *getHTTPRequestHandler(
            const HTTPRequest &requestData, const QHash<QString, QVariant> &s) const =0;
};

Q_DECLARE_INTERFACE(IPlugin, "http-daemon.IPlugin/1.0")
#endif // IHTTPREQUESTHANDLERFACTORY_H
