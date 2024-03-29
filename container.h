#ifndef CONTAINER_H
#define CONTAINER_H
#include <list>
#include "filemanager.h"
#include <thread>
#include "QDebug"

class Container
{
private:
    std::list<FileManager*> managers;
    void check();
    Container();
    ~Container();
    Container(Container const&);
    Container& operator= (Container const&);

public:
    static Container& Instance();
    void add_manager(QString &str);
    void start_tracking(int interval = 5000);
};

#endif // CONTAINER_H
