#include "tabledatamodel.h"

#include <controller/databasecontroller.h>

TableDataModel::TableDataModel( QObject *parent ) :
    QAbstractListModel( parent ) {

    _tables = DatabaseController().findTables();
}

int TableDataModel::rowCount( const QModelIndex& parent ) const {

    if( parent.isValid() ) {
        return 0;
    }

    return _tables.count();
}

QVariant TableDataModel::data( const QModelIndex& index, int role ) const {

    if ( !index.isValid() ) {
         return QVariant();
    }

    const TableModel* table = _tables.at( index.row() );

    switch ( role ) {
    case NameRole:
        return table->name();
    case ColumsRole: {
        return QVariant::fromValue( table->columns());
    }
    default:
        return QVariant();
    }

}

QHash<int, QByteArray> TableDataModel::roleNames() const {

    static QHash<int, QByteArray> mapping {
        {NameRole, "name" },
        {ColumsRole, "columns"}
    };

    return mapping;

}
