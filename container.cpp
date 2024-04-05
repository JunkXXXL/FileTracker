#include "container.h"

Container::Container()
{
    managers = std::vector<FileManager*>();
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
        FileManager* element = managers.back();
        managers.pop_back();
        delete element;
    }
}

void Container::check()
{
    emit startCheck();
    std::vector<FileManager*>::iterator it;
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

bool Container::add_manager(QString &str)
{
    std::vector<FileManager*>::iterator it;
    for (it = managers.begin(); it != managers.end(); it++)
    {
        if ((*it)->get_filePath() == str)
        {
            return false;
        }
    }
    FileManager *new_manager = new FileManager(str);
    managers.push_back(new_manager);
    return true;
}

bool Container::remove_manager(QString &str)
{

    for (int i = 0; i < (int)managers.size(); i++)
    {
        if (managers[i]->get_filePath() == str)
        {
            delete managers[i];
            managers.erase(std::next(managers.begin(), i));
            return true;
        }
        return false;
    }
}

void Container::start_tracking(int interval)
{
    while (true)
    {
        check();
        std::this_thread::sleep_for( std::chrono::milliseconds( interval ));
    }
}

