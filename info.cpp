#include "info.h"
#include "QDebug"

Info::Info(QString file_path) : QFileInfo(file_path)
{
    if (isFile())
    {
        lastChanges = lastModified();
    }
    else
    {
        lastChanges = QDateTime();
    }
}

States Info::check_changes()
{
    refresh();
    if (!isFile())
    {
        return States::NO_FILE;
    }
    else if (lastModified() == lastChanges)
    {
        return States::NO_CHANGES;
    }
    else if (lastModified() > lastChanges)
    {
        lastChanges = lastModified();
        return States::EXIST_CHANGES;
    }
}
