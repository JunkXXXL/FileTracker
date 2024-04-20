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
    if (!isFile() and lastState != States::NO_FILE)
    {
        lastState = States::NO_FILE;
        return States::NO_FILE;
    }
    else if (lastModified() == lastChanges and lastState != States::NO_CHANGES)
    {
        lastState = States::NO_CHANGES;
        return States::NOTHING_NEW;
    }
    else if (lastModified() > lastChanges)
    {
        lastState = States::EXIST_CHANGES;
        lastChanges = lastModified();
        return States::EXIST_CHANGES;
    }
    return States::NOTHING_NEW;
}
