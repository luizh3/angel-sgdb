#ifndef FILEHELPER_H
#define FILEHELPER_H

#include <QFile>

class FileHelper : public QFile {
public:
    FileHelper( const QString& dsFilePath );
    QString read();
};

#endif // FILEHELPER_H
