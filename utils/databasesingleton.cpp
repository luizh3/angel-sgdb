#include "databasesingleton.h"

#include <QDebug>
#include <QSqlDatabase>
#include <QUuid>
#include <QThread>

DatabaseSingleton::DatabaseSingleton() :
    _databases() {}

DatabaseSingleton& DatabaseSingleton::instance() {
    static DatabaseSingleton databaseSingleton;
    return databaseSingleton;
}

void DatabaseSingleton::add( const ConnectionDatabaseModel* connection ) {
    _databases.insert( connection->dsDatabaseName(), connection );
}

QSqlDatabase DatabaseSingleton::open() {
    return databaseInstance( _databases.last() );
}

QSqlDatabase DatabaseSingleton::open( const QString& dbName )  {
    return databaseInstance( _databases.value( dbName, nullptr ) );
}

const ConnectionDatabaseModel* DatabaseSingleton::connection() const {
    return _databases.last();
}

const ConnectionDatabaseModel* DatabaseSingleton::connection( const QString &dsDatabase ) const {
    return _databases.value( dsDatabase, nullptr );
}

QMap<QString, const ConnectionDatabaseModel*> DatabaseSingleton::databases() const {
    return _databases;
}

void DatabaseSingleton::setDatabases( const QMap<QString, const ConnectionDatabaseModel*> &newDatabases ) {
    _databases = newDatabases;
}

QSqlDatabase DatabaseSingleton::databaseInstance( const ConnectionDatabaseModel* connectionDatabase ) {

    if( _connectionName.hasLocalData() ){
        return QSqlDatabase::database( _connectionName.localData() );
    }

    return openByConnectionDatabase( connectionDatabase );
}

QSqlDatabase DatabaseSingleton::openByConnectionDatabase( const ConnectionDatabaseModel* connection ) {

    if( !connection ){
        qCritical() << "DatabaseSingleton::openByConnectionDatabas connection not founded";
        throw std::runtime_error("Connection not is valid!");
    }

    const QString dsConnection = connectionName();

    qInfo() << "DatabaseSingleton::openByConnectionDatabase create a new connection [DS_CONNECTION_NAME]" << dsConnection;

    QSqlDatabase databaseConnection = QSqlDatabase::addDatabase("QPSQL", dsConnection);
    databaseConnection.setHostName( connection->dsHost() );
    databaseConnection.setPort( connection->dsPort().toInt() );
    databaseConnection.setDatabaseName( connection->dsDatabaseName() );
    databaseConnection.setUserName( connection->dsUsername() );
    databaseConnection.setPassword( connection->dsPassword() );

    if( !databaseConnection.open() ) {
        qInfo() << "ConnectionDatabaseService::connect fail on open database";
        throw std::runtime_error("Failed to connect to the database, review the settings.");
    }

    return databaseConnection;
}

QString DatabaseSingleton::connectionName() {

    if( _connectionName.hasLocalData() ){
        return _connectionName.localData();
    }

    const QString dsUuid = QUuid::createUuid().toString();
    const int threadId = reinterpret_cast<qintptr>(QThread::currentThreadId());

    const QString dsConnectionName = QString("ANGEL-DATABASE-CONNECTION-%0-%1").arg( QString::number( threadId ), dsUuid );

    _connectionName.setLocalData( dsConnectionName );

    return dsConnectionName;
}
