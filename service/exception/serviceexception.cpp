#include "serviceexception.h"

ServiceException::ServiceException( const QString& title, const char* what ) :
    std::runtime_error( what ),
    _title( title ){}

QString ServiceException::title() const {
    return _title;
}
