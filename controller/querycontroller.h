#ifndef QUERYCONTROLLER_H
#define QUERYCONTROLLER_H

#include <service/queryservice.h>

class QueryController {
public:
    QueryModel* run( const QString& query ) const;
private:
    QueryService _queryService;
};

#endif // QUERYCONTROLLER_H
