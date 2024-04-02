#include "console.h"

Console::Console()
{

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

void Console::messageExistChanges(FileManager* manager)
{
    printExistChanges(manager->getName());
}

void Console::messageNoChanges(FileManager* manager)
{
    printNoChanges(manager->getName());
}

void Console::messageNoFile(FileManager* manager)
{
    printNoFile(manager->getName());
}

void Console::messageCurrentTime()
{
    printCurrentTime();
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


