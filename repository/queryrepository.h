#ifndef QUERYREPOSITORY_H
#define QUERYREPOSITORY_H

#include <QList>
#include <QString>

#include <model/query/querymodel.h>

class QueryRepository {
public:
    QueryModel* run( const QString& query ) const;
};

#endif // QUERYREPOSITORY_H
