#include "filehelper.h"

FileHelper::FileHelper(  const QString& dsFilePath ) :
    QFile( dsFilePath ){}

QString FileHelper::read() {

    if( !open(QFile::ReadOnly) ){
        throw std::runtime_error("Failed on open file!");
    }

    return readAll();
}
