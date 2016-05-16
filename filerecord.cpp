#include "filerecord.h"

FileRecord::FileRecord() : _file{nullptr}, _saved(false)
{

}

FileRecord::FileRecord(QFile *file) : _file(file), _saved(true)
{

}

FileRecord::~FileRecord()
{
    delete _file;
}

void FileRecord::save(QString &fileContents)
{
    _file->open(QIODevice::WriteOnly);
    _file->write(fileContents.toStdString().c_str(), fileContents.length());
    _file->close();
}

void FileRecord::saveAs(QString filepath, QString &fileContents)
{
    _file = new QFile(filepath);
    save(fileContents);
    _saved = true;
}

bool FileRecord::isSaved()
{
    return _saved;
}
