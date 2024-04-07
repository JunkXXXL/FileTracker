#include "info.h"
#include "QDebug"

Info::Info(QString file_path)
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

States Info::check_changes()
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

QString Info::getName() const
{
    return fileInfo.fileName();
}

QDateTime Info::getTimeChanging()
{
    return lastChanges;
}

QString Info::get_filePath()
{
    return filePath;
}
