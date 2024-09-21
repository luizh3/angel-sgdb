#include "chaincallshandler.h"

namespace {
constexpr int INDEX_NOT_FOUND = -1;
}

ChainCallsHandler& ChainCallsHandler::instance() {
    static ChainCallsHandler chainCallsHandler;
    return chainCallsHandler;
}

void ChainCallsHandler::add( HandlerCalls* handler ) {

    if( !_handlers.isEmpty() ){
        handler->setNext( _handlers.last() );
    }

    _handlers.append( handler );

}

void ChainCallsHandler::remove( HandlerCalls* handler ) {

    const int index = _handlers.indexOf( handler );

    if( index == INDEX_NOT_FOUND ) {
        return;
    }

    _handlers.removeAt( index );

    if( index <= 0 ) {
        return;
    }

    HandlerCalls* undoHandler = _handlers.at( index - 1 );
    undoHandler->setNext( handler->next() );
}
