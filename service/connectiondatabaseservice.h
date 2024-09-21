#ifndef CONNECTIONDATABASESERVICE_H
#define CONNECTIONDATABASESERVICE_H

#include <model/connection/database/connectiondatabasemodel.h>

class ConnectionDatabaseService {
public:
    void connect( ConnectionDatabaseModel* connection ) const;
};

#endif // CONNECTIONDATABASESERVICE_H
