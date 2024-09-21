#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QList>
#include <QObject>

#include "columnmodel.h"

class TableModel : public QObject {
    Q_OBJECT
    Q_PROPERTY( QString name READ name WRITE setName NOTIFY nameChanged FINAL )
    Q_PROPERTY( QList<ColumnModel*> columns READ columns CONSTANT );
public:
    TableModel();

    void addColumn( ColumnModel* column );
    QList<ColumnModel*> columns() const;

    QString name() const;
    void setName(const QString &newName);

signals:
    void nameChanged();

private:
    QString _name;
    QList<ColumnModel*> _columns;
};

#endif // TABLEMODEL_H
