#include "tablemodel.h"

TableModel::TableModel() :
    _columns( {} ){}

void TableModel::addColumn( ColumnModel* column ) {
    _columns.append( column );
}

QList<ColumnModel*> TableModel::columns() const {
    return _columns;
}

QString TableModel::name() const {
    return _name;
}

void TableModel::setName( const QString& newName ) {
    if ( _name == newName )
        return;
    _name = newName;
    emit nameChanged();
}
