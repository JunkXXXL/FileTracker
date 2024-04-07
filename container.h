#ifndef CONTAINER_H
#define CONTAINER_H
#include <vector>
#include "info.h"
#include <thread>
#include "QDebug"
#include <QObject>

class Container: public QObject
{
    Q_OBJECT
private:
    std::vector<Info*> managers;
    Container();
    ~Container();
    Container(Container const&);
    Container& operator= (Container const&);

public:
    static Container& Instance();
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

#endif // CONTAINER_H
