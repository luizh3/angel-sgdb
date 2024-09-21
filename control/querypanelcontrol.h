#ifndef QUERYPANELCONTROL_H
#define QUERYPANELCONTROL_H

#include <QObject>

#include <controller/querycontroller.h>

class QueryPanelControl : public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE void runQuery( const QString& dsQuery ) const;
private:
    QueryController _queryController;
};

#endif // QUERYPANELCONTROL_H
