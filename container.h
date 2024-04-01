#ifndef CONTAINER_H
#define CONTAINER_H
#include <list>
#include "filemanager.h"
#include <thread>
#include "QDebug"
#include <QObject>

class Container: public QObject
{
    Q_OBJECT
private:
    std::list<FileManager*> managers;
    FileManager* currentFile;
    void check();
    Container();
    ~Container();
    Container(Container const&);
    Container& operator= (Container const&);
    void setCurrentFile(FileManager* file);

public:

    static Container& Instance();
    void add_manager(QString &str);
    void start_tracking(int interval = 5000);

signals:
    void noFile(FileManager* current);
    void noChanges(FileManager* current);
    void existChanges(FileManager* current);
};

#endif // CONTAINER_H
