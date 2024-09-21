#ifndef DATABASECONTROLLER_H
#define DATABASECONTROLLER_H

#include <model/database/tablemodel.h>

class DatabaseController {
public:
    DatabaseController();

    QList<TableModel*> findTables() const;
};

#endif // DATABASECONTROLLER_H
