#include "container.h"

Container::Container()
{
    managers = std::list<FileManager*>();
}

Container &Container::Instance()
{
    static Container c;
    return c;
}

Container::~Container()
{
    while (!managers.empty())
    {
        FileManager* element = managers.front();
        managers.pop_front();
        delete element;
    }
}

void Container::check()
{
    emit startCheck();
    std::list<FileManager*>::iterator it;
    for (it = managers.begin(); it != managers.end(); it++)
    {
        int state = (int)(*it)->check_changes();
        if (state == 0)
        {
            emit noFile(*it);
        }
        else if (state == 1)
        {
            emit noChanges(*it);
        }
        else if (state == 2)
        {
            emit existChanges(*it);
        }
    }
}

void Container::add_manager(QString &str)
{
    FileManager *new_manager = new FileManager(str);
    managers.push_front(new_manager);
}

void Container::start_tracking(int interval)
{
    while (true)
    {
        check();
        std::this_thread::sleep_for( std::chrono::milliseconds( interval ));
    }
}

