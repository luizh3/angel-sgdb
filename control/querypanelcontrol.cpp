#include "querypanelcontrol.h"

#include <utils/synctask.h>

void QueryPanelControl::runQuery( const QString& dsQuery ) const {

    QueryModel* query = nullptr;

    SyncTask::runSync<QueryModel>([&](){
        query = _queryController.run( dsQuery );
    }, query );


    query->columns();
}
