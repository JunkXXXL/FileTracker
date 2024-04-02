#ifndef CONTAINER_H
#define CONTAINER_H
#include <vector>
#include "filemanager.h"
#include <thread>
#include "QDebug"
#include <QObject>

class Container: public QObject
{
    Q_OBJECT
private:
    std::vector<FileManager*> managers;
    void check();
    Container();
    ~Container();
    Container(Container const&);
    Container& operator= (Container const&);

public:

    static Container& Instance();
    bool add_manager(QString &str);
    bool remove_manager(QString &str);
    void start_tracking(int interval = 5000);

signals:
    void noFile(FileManager* current);
    void noChanges(FileManager* current);
    void existChanges(FileManager* current);
    void startCheck();
};

#endif // CONTAINER_H
