#ifndef DATABASESERVICE_H
#define DATABASESERVICE_H

#include <repository/databaserepository.h>

class DatabaseService {
public:
    DatabaseService();
    QList<TableModel*> findTables() const;
private:
    DatabaseRepository _databaseRepository;
};

#endif // DATABASESERVICE_H
