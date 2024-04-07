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
    void printNoChanges(QString name);
    void printNoFile(QString name);
    void printExistChanges(QString name);
    void printNewFile(QString name);
public:
    static Console& Instance();
    void printCurrentTime();

public slots:
    void messageExistChanges(Info* manager);
    void messageNoChanges(Info* manager);
    void messageNoFile(Info* manager);
    void messageCurrentTime();
    void addfile(Info* manager);
};

#endif // CONSOLE_H
