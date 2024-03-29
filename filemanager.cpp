#include "filemanager.h"
#include "QDebug"

FileManager::FileManager(QString file_path)
{
    filePath = file_path;
    QFileInfo fileInfo = QFileInfo(file_path);
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
    QFileInfo fileInfo = QFileInfo(filePath);
    qDebug() << fileInfo.fileName();
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

QString FileManager::get_name()
{

}
