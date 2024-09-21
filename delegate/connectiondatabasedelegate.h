#ifndef CONNECTIONDATABASEDELEGATE_H
#define CONNECTIONDATABASEDELEGATE_H

#include <service/connectiondatabaseservice.h>

class ConnectionDatabaseDelegate {
public:
    void connect( ConnectionDatabaseModel* connection ) const;
};

#endif // CONNECTIONDATABASEDELEGATE_H
