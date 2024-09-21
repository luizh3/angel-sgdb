#ifndef BASEHANDLERCALLS_H
#define BASEHANDLERCALLS_H

#include "handlercalls.h"

class BaseHandlerCalls : public HandlerCalls {
public:
    HandlerCalls* next();
    void setNext( HandlerCalls* next );
    void toastSuccess( const QString& title, const QString& description );
    void toastError( const QString& title, const QString& description );
    void toastWarning( const QString& title, const QString& description );
private:
    HandlerCalls* _next;
};

#endif // BASEHANDLERCALLS_H
