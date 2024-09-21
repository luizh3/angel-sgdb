#include "querymodel.h"

QueryModel::QueryModel( const QList<QList<QString> >& values, const QList<QString>& columns ) :
    _values( values ),
    _columns( columns ){}

QList<QList<QString> > QueryModel::values() const {
    return _values;
}

void QueryModel::setValues( const QList<QList<QString> >& values ) {
    _values = values;
}

QList<QString> QueryModel::columns() const {
    return _columns;
}

void QueryModel::setColumns( const QList<QString>& columns ) {
    _columns = columns;
}
