#ifndef CHANGETRACKER_H
#define CHANGETRACKER_H
#include <vector>
#include "info.h"
#include <thread>
#include "QDebug"
#include <QObject>

class ChangeTracker: public QObject
{
    Q_OBJECT
private:
    std::vector<Info*> managers;
    ChangeTracker();
    ~ChangeTracker();
    ChangeTracker(ChangeTracker const&);
    ChangeTracker& operator= (ChangeTracker const&);

public:
    static ChangeTracker& Instance();
    bool add_file(QString &str);
    bool remove_file(QString &str);
    void check(bool all_notification = false);

signals:
    void addNewFile(Info* current);
    void removeFile(Info* current);
    void noFile(Info* current);
    void noChanges(Info* current);
    void existChanges(Info* current);
};

#endif // CHANGETRACKER_H
