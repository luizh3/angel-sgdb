#include "querycontroller.h"

QueryModel* QueryController::run( const QString& query ) const {
    return _queryService.run( query );
}
