#include "connectiondatabasemodel.h"

ConnectionDatabaseModel::ConnectionDatabaseModel( QObject* parent ) : QObject{parent} {}

QString ConnectionDatabaseModel::dsHost() const {
    return _dsHost;
}

void ConnectionDatabaseModel::setDsHost( const QString& newDsHost) {
    if (_dsHost == newDsHost)
        return;
    _dsHost = newDsHost;
    emit dsHostChanged();
}

QString ConnectionDatabaseModel::dsPort() const {
    return _dsPort;
}

void ConnectionDatabaseModel::setDsPort( const QString &newDsPort) {
    if (_dsPort == newDsPort)
        return;
    _dsPort = newDsPort;
    emit dsPortChanged();
}

QString ConnectionDatabaseModel::dsDatabaseName() const {
    return _dsDatabaseName;
}

void ConnectionDatabaseModel::setDsDatabaseName( const QString& newDsDatabaseName ) {
    if (_dsDatabaseName == newDsDatabaseName)
        return;
    _dsDatabaseName = newDsDatabaseName;
    emit dsDatabaseNameChanged();
}

QString ConnectionDatabaseModel::dsUsername() const {
    return _dsUsername;
}

void ConnectionDatabaseModel::setDsUsername( const QString& newDsUsername) {
    if (_dsUsername == newDsUsername)
        return;
    _dsUsername = newDsUsername;
    emit dsUsernameChanged();
}

QString ConnectionDatabaseModel::dsPassword() const {
    return _dsPassword;
}

void ConnectionDatabaseModel::setDsPassword( const QString& newDsPassword) {
    if (_dsPassword == newDsPassword)
        return;
    _dsPassword = newDsPassword;
    emit dsPasswordChanged();
}
