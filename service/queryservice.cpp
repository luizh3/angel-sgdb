#include "queryservice.h"


QueryModel* QueryService::run( const QString& query ) const {
    return _queryRepository.run( query );
}
