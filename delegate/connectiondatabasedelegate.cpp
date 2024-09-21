#include "connectiondatabasedelegate.h"

void ConnectionDatabaseDelegate::connect( ConnectionDatabaseModel* connection ) const {
    return ConnectionDatabaseService().connect( connection );
}
