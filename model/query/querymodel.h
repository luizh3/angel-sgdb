#ifndef QUERYMODEL_H
#define QUERYMODEL_H

#include <QList>
#include <QObject>

class QueryModel : public QObject {
    Q_OBJECT
    Q_PROPERTY(QList<QList<QString> > values READ values WRITE setValues NOTIFY valuesChanged FINAL)
    Q_PROPERTY(QList<QString> columns READ columns WRITE setColumns NOTIFY columnsChanged FINAL)
public:
    explicit QueryModel( const QList<QList<QString> >& values, const QList<QString>& columns );

    QList<QList<QString> > values() const;
    void setValues(  const QList<QList<QString> >& values);

    QList<QString> columns() const;
    void setColumns( const QList<QString>& columns );

signals:
    void valuesChanged();
    void columnsChanged();

private:
    QList<QList<QString>> _values;
    QList<QString> _columns;
};

#endif // QUERYMODEL_H
