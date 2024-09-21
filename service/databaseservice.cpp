#include "databaseservice.h"

#include <QSqlRecord>
#include <QSqlQuery>
#include <QSqlField>

#include <utils/databasesingleton.h>

DatabaseService::DatabaseService() {}

QList<TableModel*> DatabaseService::findTables() const {

    const ConnectionDatabaseModel* connection = DatabaseSingleton::instance().connection();

    return _databaseRepository.findTables( connection->dsDatabaseName(), QStringLiteral( "public" ) );

}
