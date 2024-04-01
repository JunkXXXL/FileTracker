#ifndef CONSOLE_H
#define CONSOLE_H
#include "QString"
#include "QDebug"
#include "QDateTime"

class Console
{
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
    void messageExistChanges();
    void messageNoChanges();
    void messageNoFile();
};

#endif // CONSOLE_H
