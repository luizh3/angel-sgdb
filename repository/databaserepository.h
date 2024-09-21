#ifndef DATABASEREPOSITORY_H
#define DATABASEREPOSITORY_H

#include <QString>

#include <model/database/tablemodel.h>

class DatabaseRepository {
public:
    QList<TableModel*> findTables( const QString& dsDatabase, const QString& dsSchema ) const;
};

#endif // DATABASEREPOSITORY_H
