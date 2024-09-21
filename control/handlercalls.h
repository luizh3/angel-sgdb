#ifndef HANDLERCALLS_H
#define HANDLERCALLS_H

#include <QString>

class HandlerCalls {
public:
    virtual HandlerCalls* next() = 0;
    virtual void setNext( HandlerCalls* next ) = 0;
    virtual void toastSuccess( const QString& title, const QString& description ) = 0;
    virtual void toastError( const QString& title, const QString& description ) = 0;
    virtual void toastWarning( const QString& title, const QString& description ) = 0;
};

#endif // HANDLERCALLS_H
