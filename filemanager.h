#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include "QString"
#include "QFileInfo"
#include "QDateTime"

enum class States{
    NO_FILE=0,
    NO_CHANGES,
    EXIST_CHANGES
};

class FileManager
{
public:
    FileManager(QString file_path);
    States check_changes();
    QString getName() const;
    QDateTime getTimeChanging();

private:
    QString filePath;
    QDateTime lastChanges;
    QFileInfo fileInfo;
};

#endif // FILEMANAGER_H
