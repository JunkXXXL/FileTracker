#ifndef CONSOLE_H
#define CONSOLE_H
#include "QString"
#include "QDebug"
#include "QDateTime"
#include "container.h"

class Console: public QObject
{
Q_OBJECT

private:
    Console();
    ~Console();
    Console(Console const&);
    Console& operator=(Console const&);
    void printNoChanges(QString path);
    void printNoFile(QString path);
    void printExistChanges(QString path);
public:
    static Console& Instance();
    void printCurrentTime();

public slots:
    void messageExistChanges(FileManager* manager);
    void messageNoChanges(FileManager* manager);
    void messageNoFile(FileManager* manager);
    void messageCurrentTime();
};

#endif // CONSOLE_H
