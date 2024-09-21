#ifndef SQLRECORDFILE_H
#define SQLRECORDFILE_H

#include <QList>
#include <QSqlRecord>

class SqlRecordFile {
public:
    explicit SqlRecordFile( const QSqlRecord record );

    QList<QString> fields() const;
    QList<QString> columns() const;

private:
    const QSqlRecord _record;
};

#endif // SQLRECORDFILE_H
