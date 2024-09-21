#include "databasecontroller.h"

#include <service/databaseservice.h>

DatabaseController::DatabaseController() {}

QList<TableModel*> DatabaseController::findTables() const {
    return DatabaseService().findTables();
}
