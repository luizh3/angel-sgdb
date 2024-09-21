#include "databaserepository.h"

#include <QSqlRecord>
#include <QSqlQuery>
#include <QSqlField>

#include <utils/sqlqueryfile.h>

QList<TableModel*> DatabaseRepository::findTables( const QString& dsDatabase, const QString& dsSchema ) const {

    SqlQueryFile sqlQueryFile(":/sqls/find_all_tables.sql");
    sqlQueryFile.bindByName( "DATABASE", dsDatabase );
    sqlQueryFile.bindByName( "SCHEMA", dsSchema );

    return sqlQueryFile.toListByKey<TableModel*>( "table_name",
        []( const QSqlRecord& record, TableModel* table ) -> void {

            ColumnModel* column = new ColumnModel();
            column->setName( record.value( "column_name" ).toString() );

            table->addColumn( column );

        },
        []( const QSqlRecord& record ) -> TableModel* {

            TableModel* table = new TableModel();
            table->setName( record.value( "table_name" ).toString() );

            ColumnModel* column = new ColumnModel();
            column->setName( record.value( "column_name" ).toString() );

            table->addColumn( column );

            return table;
        });

}
