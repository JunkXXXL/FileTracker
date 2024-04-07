#include "console.h"

Console::Console()
{
    Container &cont = Container::Instance();
    QObject::connect(&cont, &Container::startCheck, this, &Console::messageCurrentTime);
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
    printExistChanges(manager->getName());
}

void Console::messageNoChanges(Info* manager)
{
    printNoChanges(manager->getName());
}

void Console::messageNoFile(Info* manager)
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


