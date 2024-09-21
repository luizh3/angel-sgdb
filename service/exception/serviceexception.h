#ifndef SERVICEEXCEPTION_H
#define SERVICEEXCEPTION_H

#include <stdexcept>

#include <QString>

class ServiceException : public std::runtime_error {
public:
    explicit ServiceException( const QString& title, const char* what );
    QString title() const;
private:
    QString _title;
};

#endif // SERVICEEXCEPTION_H
