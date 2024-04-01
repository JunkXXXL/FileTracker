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
    qDebug() << "\nCurrent time " << time.time();
}

void Console::messageExistChanges()
{

}

void Console::printNoChanges(QString name)
{
    qDebug() << "File " << name << " doesn't changes";
}

void Console::printNoFile(QString path)
{
    qDebug() << "File " << path << " not exist";
}

void Console::printExistChanges(QString name)
{
    qDebug() << "File " << name << " changed!!!";
}


