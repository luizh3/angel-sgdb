#ifndef CONNECTIONDATABASECONTROLLER_H
#define CONNECTIONDATABASECONTROLLER_H

class ConnectionDatabaseModel;
class ConnectionDatabaseController {
public:
    void connect( ConnectionDatabaseModel* connection ) const;
};

#endif // CONNECTIONDATABASECONTROLLER_H
