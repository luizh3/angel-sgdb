#include "basehandlercalls.h"


HandlerCalls* BaseHandlerCalls::next() {
    return _next;
}

void BaseHandlerCalls::setNext( HandlerCalls* next ) {
    _next = next;
}

void BaseHandlerCalls::toastSuccess( const QString& title, const QString& description ) {
    if( _next ) {
        _next->toastSuccess( title, description );
    }
}

void BaseHandlerCalls::toastError( const QString& title, const QString& description ) {
    if( _next ) {
        _next->toastError( title, description );
    }
}

void BaseHandlerCalls::toastWarning( const QString& title, const QString& description ) {
    if( _next ) {
        _next->toastWarning( title, description );
    }
}
