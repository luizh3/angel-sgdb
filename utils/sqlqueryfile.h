#ifndef SQLQUERYFILE_H
#define SQLQUERYFILE_H

#include <QList>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QMap>
#include <QVariant>

#include "sqlrecordfile.h"

class SqlQueryFile : public QSqlQuery {
public:
    SqlQueryFile( const QString& dsSqlFilePath = "" );

    void bindByName( QString placeholder, const QVariant& value, QSql::ParamType type = QSql::In);

    template<typename T>
    QList<T> toList( std::function<T( const SqlRecordFile& record )> toObject) {
        QList<T> values = {};

        exec();

        while( next()){
            values.append( toObject(SqlRecordFile(record())));
        }

        return values;

    };


    QList<QString> columns() const;

    template<typename T>
    QList<T> toListByKey( QString keyRecord,
                         std::function<void( const QSqlRecord& record, T existentRecord )> toObjectExistRecord,
                         std::function<T( const QSqlRecord& record )> toObjectNewRecord  ) {

        QMap<QString,T> recordByKey = {};

        exec();

        while( next() ){

            const QString dsCurrentKey = value(keyRecord).toString();

            bool hasRecordByKey = recordByKey.contains( dsCurrentKey );

            if( hasRecordByKey ) {
                toObjectExistRecord( record(), recordByKey[dsCurrentKey] );
                continue;
            }

            recordByKey.insert( dsCurrentKey, toObjectNewRecord( record() ) );

        }

        return recordByKey.values();

    };

};

#endif // SQLQUERYFILE_H
