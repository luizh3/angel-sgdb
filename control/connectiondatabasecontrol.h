#ifndef CONNECTIONDATABASECONTROL_H
#define CONNECTIONDATABASECONTROL_H

#include "control.h"

#include <model/connection/database/connectiondatabasemodel.h>

class ConnectionDatabaseControl : public Control {
    Q_OBJECT
public slots:
    void onConnect( ConnectionDatabaseModel* connection );
signals:
    void error();
    void success();
};

#endif // CONNECTIONDATABASECONTROL_H
