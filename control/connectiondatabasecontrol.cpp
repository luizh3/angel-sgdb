#include "connectiondatabasecontrol.h"

#include <QDebug>

#include <utils/synctask.h>

#include <service/exception/serviceexception.h>
#include <controller/connectiondatabasecontroller.h>

void ConnectionDatabaseControl::onConnect( ConnectionDatabaseModel* connection ) {

    qInfo() << "ConnectionDatabaseControl::onConnect";

    SyncTask::runSync( [&]() -> void {
        try {
            ConnectionDatabaseController().connect( connection );
            toastSuccess( tr("Success!"), tr("Database connected") );
            emit success();
            emit finished();
        } catch ( ServiceException& exception ) {
            qInfo() << "ConnectionDatabaseControl::onConnect [WHAT]" << exception.what();
            toastError( exception.title(), exception.what() );
            emit error();
        }
    });

    qInfo() << "ConnectionDatabaseControl::onConnect";
}
