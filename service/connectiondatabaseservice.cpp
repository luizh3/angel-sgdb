#include "connectiondatabaseservice.h"

#include <QSqlDatabase>

#include <QDebug>

#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlField>

#include <utils/databasesingleton.h>
#include <service/exception/serviceexception.h>

void ConnectionDatabaseService::connect( ConnectionDatabaseModel* connection ) const {

    ConnectionDatabaseModel* connectionDatabaseModel = new ConnectionDatabaseModel();
    connectionDatabaseModel->setDsDatabaseName( connection->dsDatabaseName() );
    connectionDatabaseModel->setDsUsername( connection->dsUsername() );
    connectionDatabaseModel->setDsHost( connection->dsHost() );
    connectionDatabaseModel->setDsPort( connection->dsPort() );
    connectionDatabaseModel->setDsPassword( connection->dsPassword() );

    DatabaseSingleton::instance().add( connectionDatabaseModel );

    try {
        DatabaseSingleton::instance().open();
    } catch ( std::runtime_error& exception ) {
        qCritical() << "ConnectionDatabaseService::connect [WHAT]" << exception.what();
        throw ServiceException("Failed to connected!", exception.what() );
    }

}
