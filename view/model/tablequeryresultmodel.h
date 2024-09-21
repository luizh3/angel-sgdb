#ifndef TABLEQUERYRESULTMODEL_H
#define TABLEQUERYRESULTMODEL_H

#include <QObject>
#include <QSqlQueryModel>

class TableQueryResultModel : public QSqlQueryModel {
    Q_OBJECT
    Q_PROPERTY( QString dsQuery READ dsQuery WRITE setDsQuery NOTIFY dsQueryChanged FINAL )
    Q_PROPERTY( QString dsError READ dsError WRITE setDsError NOTIFY dsErrorChanged FINAL )
public:
    QString dsQuery() const;
    void setDsQuery( const QString& dsQuery );

    QString dsError() const;
    void setDsError(const QString& dsError );

signals:
    void dsQueryChanged();
    void dsErrorChanged();

private:
    QString _dsError;
};

#endif // TABLEQUERYRESULTMODEL_H
