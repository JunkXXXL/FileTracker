#ifndef CONSOLE_H
#define CONSOLE_H
#include "QString"
#include "QDebug"
#include "QDateTime"
#include "ChangeTracker.h"

class Console: public QObject
{
Q_OBJECT

private:
    Console();
    ~Console();
    Console(Console const&);
    Console& operator=(Console const&);
    bool print_size = false;
    void printNoChanges(QString name);
    void printNoFile(QString name);
    void printExistChanges(QString name);
    void printNewFile(QString name);
    void printRemoveFile(QString name);
    void printSize(qint64 size);
public:
    static Console& Instance();
    void set_print(bool set_prnt);
    void printCurrentTime();

public slots:
    void messageExistChanges(Info* manager);
    void messageNoChanges(Info* manager);
    void messageNoFile(Info* manager);
    void messageCurrentTime();
    void messageAddFile(Info* manager);
    void messageRemoveFile(Info* manager);
};

#endif // CONSOLE_H
