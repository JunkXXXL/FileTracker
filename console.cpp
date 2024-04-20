#include "console.h"

Console::Console()
{
    ChangeTracker &cont = ChangeTracker::Instance();
    QObject::connect(&cont, &ChangeTracker::addNewFile, this, &Console::messageAddFile);
    QObject::connect(&cont, &ChangeTracker::removeFile, this, &Console::messageRemoveFile);
    QObject::connect(&cont, &ChangeTracker::noChanges, this, &Console::messageNoChanges);
    QObject::connect(&cont, &ChangeTracker::existChanges, this, &Console::messageExistChanges);
    QObject::connect(&cont, &ChangeTracker::noFile, this, &Console::messageNoFile);
}

Console::~Console()
{

}

Console& Console::Instance()
{
    static Console c;
    return c;
}

void Console::set_print(bool set_prnt)
{
    print_size = set_prnt;
}

void Console::printCurrentTime()
{
    QDateTime time = QDateTime::currentDateTime();
    qDebug() << "\nCurrent time " << time.time().toString();
}

void Console::messageExistChanges(Info* manager)
{
    printExistChanges(manager->fileName());
    if (print_size) printSize(manager->size());
}

void Console::messageNoChanges(Info* manager)
{
    printNoChanges(manager->fileName());
    if (print_size) printSize(manager->size());
}

void Console::messageNoFile(Info* manager)
{
    printNoFile(manager->fileName());
    if (print_size) printSize(manager->size());
}

void Console::messageCurrentTime()
{
    printCurrentTime();
}

void Console::messageAddFile(Info *manager)
{
    printNewFile(manager->fileName());
    if (print_size) printSize(manager->size());
}

void Console::messageRemoveFile(Info* manager)
{
    printRemoveFile(manager->fileName());
}

void Console::printNoChanges(QString name)
{
    qDebug() << "File " << name << " didn't changed";
}

void Console::printNoFile(QString name)
{
    qDebug() << "File " << name << " not exist";
}

void Console::printExistChanges(QString name)
{
    qDebug() << "File " << name << " changed!!!";
}

void Console::printNewFile(QString name)
{
    qDebug() << "File " << name << " has been added to container";
}

void Console::printRemoveFile(QString name)
{
    qDebug() << "File " << name << " has been removed from container";
}

void Console::printSize(qint64 size)
{
    qDebug() << "file size " << size << " bytes";
}
