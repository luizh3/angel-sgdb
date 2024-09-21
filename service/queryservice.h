#ifndef QUERYSERVICE_H
#define QUERYSERVICE_H

#include <repository/queryrepository.h>

class QueryService {
public:
    QueryModel* run( const QString& query ) const;
private:
    QueryRepository _queryRepository;
};

#endif // QUERYSERVICE_H
