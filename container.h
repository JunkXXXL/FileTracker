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
    void check();
    Container();
    ~Container();
    Container(Container const&);
    Container& operator= (Container const&);

public:
    static Container& Instance();
    bool add_file(QString &str);
    bool remove_file(QString &str);
    //void start_tracking(int interval = 5000);

signals:
    void addNewFile(Info* current);
    void noFile(Info* current);
    void noChanges(Info* current);
    void existChanges(Info* current);
    void startCheck();
};

#endif // CONTAINER_H
