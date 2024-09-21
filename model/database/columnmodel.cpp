#include "columnmodel.h"

ColumnModel::ColumnModel() :
    _name( "" ) {}

QString ColumnModel::name() const {
    return _name;
}

void ColumnModel::setName(const QString &newName) {
    if (_name == newName) {
        return;
    }
    _name = newName;
    emit nameChanged();
}
