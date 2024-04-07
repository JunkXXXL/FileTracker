#include "console.h"

Console::Console()
{
    Container &cont = Container::Instance();
    QObject::connect(&cont, &Container::addNewFile, this, &Console::messageAddFile);
    QObject::connect(&cont, &Container::removeFile, this, &Console::messageRemoveFile);
    QObject::connect(&cont, &Container::noChanges, this, &Console::messageNoChanges);
    QObject::connect(&cont, &Container::existChanges, this, &Console::messageExistChanges);
    QObject::connect(&cont, &Container::noFile, this, &Console::messageNoFile);
}

Console::~Console()
{

}

Console& Console::Instance()
{
    static Console c;
    return c;
}

void Console::printCurrentTime()
{
    QDateTime time = QDateTime::currentDateTime();
    qDebug() << "\nCurrent time " << time.time().toString();
}

void Console::messageExistChanges(Info* manager)
{
    printExistChanges(manager->fileName());
}

void Console::messageNoChanges(Info* manager)
{
    printNoChanges(manager->fileName());
}

void Console::messageNoFile(Info* manager)
{
    printNoFile(manager->fileName());
}

void Console::messageCurrentTime()
{
    printCurrentTime();
}

void Console::messageAddFile(Info *manager)
{
    printNewFile(manager->fileName());
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
