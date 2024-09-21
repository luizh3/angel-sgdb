#include "mainscreencontrol.h"


void MainScreenControl::toastSuccess( const QString& title, const QString& description ) {
    emit showToastSuccess( title, description );
}

void MainScreenControl::toastWarning( const QString& title, const QString& description ) {
    emit showToastWarning( title, description );
}

void MainScreenControl::toastError( const QString& title, const QString& description ) {
    emit showToastError( title, description );
}
