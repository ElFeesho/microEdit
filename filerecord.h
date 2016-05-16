#ifndef FILERECORD_H
#define FILERECORD_H

#include <QFile>

class FileRecord
{
public:
    FileRecord();
    FileRecord(QFile *file);
    ~FileRecord();
    void save(QString &fileContents);
    void saveAs(QString filepath, QString &fileContents);
    bool isSaved();
private:
    bool _saved;
    QFile *_file;
};

#endif // FILERECORD_H
