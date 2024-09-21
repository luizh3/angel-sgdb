#include "control.h"

#include "chaincallshandler.h"

Control::Control() {
    ChainCallsHandler::instance().add( this );
}

Control::~Control(){
    ChainCallsHandler::instance().remove( this );
}
