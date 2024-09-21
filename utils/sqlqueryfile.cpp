#include "sqlqueryfile.h"

#include <QDebug>

#include "databasesingleton.h"
#include "sqlqueryfile.h"
#include "filehelper.h"

SqlQueryFile::SqlQueryFile( const QString& dsSqlFilePath ) :
    QSqlQuery( DatabaseSingleton::instance().open() ) {

    if( dsSqlFilePath.isEmpty() ){
        return;
    }

    try {
        prepare( FileHelper( dsSqlFilePath ).read() );
    } catch ( std::runtime_error& exception ) {
        qCritical() << "SqlQueryFile::SqlQueryFile [WHAT]" << exception.what();
    }
}

void SqlQueryFile::bindByName( QString placeholder, const QVariant& value, QSql::ParamType type ) {
    bindValue( placeholder.prepend( ":" ), value, type );
}

QList<QString> SqlQueryFile::columns() const {
    return SqlRecordFile( record() ).columns();
}
