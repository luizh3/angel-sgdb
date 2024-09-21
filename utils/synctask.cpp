#include "synctask.h"

void SyncTask::runSync( std::function<void ()> callBack ) {

    QEventLoop eventLoop;
    QFutureWatcher<void> future;

    QObject::connect( &future, &QFutureWatcher<void>::finished, &eventLoop, &QEventLoop::quit );

    future.setFuture( QtConcurrent::run( callBack ) );
    eventLoop.exec();
}
