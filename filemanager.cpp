#include "filemanager.h"
#include "QDebug"

FileManager::FileManager(QString file_path)
{
    filePath = file_path;
    fileInfo = QFileInfo(file_path);
    if (fileInfo.isFile())
    {
        lastChanges = fileInfo.lastModified();
    }
    else
    {
        lastChanges = QDateTime();
    }
}

States FileManager::check_changes()
{
    fileInfo.refresh();
    if (!fileInfo.isFile())
    {
        return States::NO_FILE;
    }
    else if (fileInfo.lastModified() == lastChanges)
    {
        return States::NO_CHANGES;
    }
    else if (fileInfo.lastModified() > lastChanges)
    {
        lastChanges = fileInfo.lastModified();
        return States::EXIST_CHANGES;
    }
}

QString FileManager::getName() const
{
    return fileInfo.fileName();
}

QDateTime FileManager::getTimeChanging()
{
    return lastChanges;
}
