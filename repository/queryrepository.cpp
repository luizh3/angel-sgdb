#include "queryrepository.h"

#include <QSqlRecord>
#include <QSqlQuery>
#include <QSqlField>
#include <QSqlResult>

#include <utils/sqlqueryfile.h>

using ListString = QList<QString>;

QueryModel* QueryRepository::run( const QString& query ) const {

    SqlQueryFile sqlQueryFile;
    sqlQueryFile.prepare( query );

    QList<ListString> values = sqlQueryFile.toList<ListString>([&]( const SqlRecordFile& record ){
        return record.fields();
    });

    QList<QString> columns = sqlQueryFile.columns();

    return new QueryModel( values, columns );
}
