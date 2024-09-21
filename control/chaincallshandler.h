#ifndef CHAINCALLSHANDLER_H
#define CHAINCALLSHANDLER_H

#include <QList>

#include "handlercalls.h"

class ChainCallsHandler {
public:
    static ChainCallsHandler& instance();

    void add( HandlerCalls* handler );
    void remove( HandlerCalls* handler );

private:
    QList<HandlerCalls*> _handlers;
};

#endif // CHAINCALLSHANDLER_H
