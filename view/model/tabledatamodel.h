#ifndef TABLEDATAMODEL_H
#define TABLEDATAMODEL_H

#include <QAbstractListModel>

#include <model/database/tablemodel.h>

class TableDataModel : public QAbstractListModel {
    Q_OBJECT
public:
    explicit TableDataModel( QObject *parent = nullptr );

    enum Roles {
        NameRole = Qt::UserRole,
        ColumsRole,
    };

    int rowCount(const QModelIndex& parent) const override;

    QVariant data( const QModelIndex& index, int role = Qt::DisplayRole ) const override;


    QHash<int, QByteArray> roleNames() const override;

private:
    QList<TableModel*> _tables;
};

#endif // TABLEDATAMODEL_H
