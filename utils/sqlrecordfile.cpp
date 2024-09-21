#include "sqlrecordfile.h"

#include <QVariant>

SqlRecordFile::SqlRecordFile( const QSqlRecord record ) :
    _record( record ) {}

QList<QString> SqlRecordFile::fields() const {

    QList<QString> values = {};

    for( int index = 0; index < _record.count(); index++ ) {
        values.append( _record.value( index ).toString() );
    }

    return values;
}

QList<QString> SqlRecordFile::columns() const {

    QList<QString> columns = {};

    for( int index = 0; index < _record.count(); index++ ){
        columns.append( _record.fieldName( index ) );
    }

    return columns;

}
