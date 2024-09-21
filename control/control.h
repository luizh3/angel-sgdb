#ifndef CONTROL_H
#define CONTROL_H

#include <QObject>

#include "basehandlercalls.h"

class Control : public QObject, public BaseHandlerCalls {
    Q_OBJECT
public:
    Control();
    ~Control();
signals:
    void finished();
};

#endif // CONTROL_H
