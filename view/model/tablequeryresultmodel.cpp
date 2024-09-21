#include "tablequeryresultmodel.h"

#include <utils/synctask.h>
#include <utils/databasesingleton.h>
#include <utils/sqlrecordfile.h>

#include <QSqlRecord>
#include <QSqlQuery>
#include <QSqlError>


QString TableQueryResultModel::dsQuery() const {
    return query().lastQuery();
}

void TableQueryResultModel::setDsQuery( const QString& dsQuery ){

    setQuery( dsQuery, DatabaseSingleton::instance().open() );

    if ( lastError().isValid() ) {
        setDsError( lastError().databaseText() );
    }

}

QString TableQueryResultModel::dsError() const {
    return _dsError;
}

void TableQueryResultModel::setDsError(const QString& dsError ) {

    if (_dsError == dsError) {
        return;
    }

    _dsError = dsError;
    emit dsErrorChanged();
}
