#ifndef CONSOLE_H
#define CONSOLE_H
#include "QString"

class Console
{
private:
    Console();
    ~Console();
    Console(Console const&);
    Console& operator=(Console const&);
public:
    static Console& Instance();
    void printCurrentTime();
    void printNoChanges(QString path);
    void printNoFile(QString path);
    void printExistChanges(QString path);
};

#endif // CONSOLE_H
