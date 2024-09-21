#ifndef MAINSCREENCONTROL_H
#define MAINSCREENCONTROL_H

#include "control.h"

class MainScreenControl : public Control {
    Q_OBJECT
public:
    void toastSuccess( const QString& title, const QString& description ) override;
    void toastWarning( const QString& title, const QString& description ) override;
    void toastError( const QString& title, const QString& description ) override;
signals:
    void showToastSuccess( const QString& title, const QString& description );
    void showToastWarning( const QString& title, const QString& description );
    void showToastError( const QString& title, const QString& description );
};

#endif // MAINSCREENCONTROL_H
