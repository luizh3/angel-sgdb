#ifndef DATABASESINGLETON_H
#define DATABASESINGLETON_H

#include <QMap>
#include <QThreadStorage>
#include <QSqlDatabase>

#include <model/connection/database/connectiondatabasemodel.h>

class DatabaseSingleton {
public:
    DatabaseSingleton();

    static DatabaseSingleton& instance();

    void add( const ConnectionDatabaseModel* connection );

    QSqlDatabase open();
    QSqlDatabase open( const QString& dbName );

    const ConnectionDatabaseModel* connection() const;
    const ConnectionDatabaseModel* connection( const QString& dsDatabase ) const;

    QMap<QString, const ConnectionDatabaseModel*> databases() const;
    void setDatabases( const QMap<QString, const ConnectionDatabaseModel*>& newDatabases );

private:
    QMap<QString, const ConnectionDatabaseModel*> _databases;
    QThreadStorage<QString> _connectionName;

    QSqlDatabase databaseInstance( const ConnectionDatabaseModel* connectionDatabase );

    QSqlDatabase openByConnectionDatabase( const ConnectionDatabaseModel* connectionDatabase );
    QString connectionName();


};

#endif // DATABASESINGLETON_H
