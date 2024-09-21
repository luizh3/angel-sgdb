#ifndef SYNCTASK_H
#define SYNCTASK_H

#include <functional>

#include <QEventLoop>
#include <QFutureWatcher>
#include <QtConcurrent>

class SyncTask {
public:
    static void runSync( std::function<void ()> callBack );

    template<typename MoveObject>
    static void runSync(std::function<void()> callBack, MoveObject*& moveObject) {
        static_assert(std::is_base_of<QObject, MoveObject>::value, "MoveObject must inherit from QObject");

        QEventLoop eventLoop;
        QFutureWatcher<void> future;

        QObject::connect(&future, &QFutureWatcher<void>::finished, &eventLoop, &QEventLoop::quit);

        QThread* currentThread = QThread::currentThread();

        future.setFuture(QtConcurrent::run([&]() {
            callBack();
            moveObject->moveToThread(currentThread);
        }));

        eventLoop.exec();
    }

};

#endif // SYNCTASK_H
