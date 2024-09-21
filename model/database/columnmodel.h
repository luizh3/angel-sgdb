#ifndef COLUMNMODEL_H
#define COLUMNMODEL_H

#include <QString>
#include <QObject>

class ColumnModel : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged FINAL)
public:
    ColumnModel();

    QString name() const;
    void setName( const QString& newName );

signals:
    void nameChanged();

private:
    QString _name;
};

#endif // COLUMNMODEL_H
