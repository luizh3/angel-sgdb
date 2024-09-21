#include "connectiondatabasecontroller.h"

#include <delegate/connectiondatabasedelegate.h>

void ConnectionDatabaseController::connect( ConnectionDatabaseModel* connection ) const {
    ConnectionDatabaseDelegate().connect( connection );
}
