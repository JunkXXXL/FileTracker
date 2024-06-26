#include "ChangeTracker.h"

ChangeTracker::ChangeTracker()
{
    managers = std::vector<Info*>();
}

ChangeTracker &ChangeTracker::Instance()
{
    static ChangeTracker c;

    return c;
}

ChangeTracker::~ChangeTracker()
{
    while (!managers.empty())
    {
        Info* element = managers.back();
        managers.pop_back();
        delete element;
    }
}

void ChangeTracker::check(bool all_notification)
{
    std::vector<Info*>::iterator it;
    for (it = managers.begin(); it != managers.end(); it++)
    {
        int state = (int)(*it)->check_changes();
        if (state == 0)
        {
            emit noFile(*it);
        }
        else if (state == 1 and all_notification)
        {
            emit noChanges(*it);
        }
        else if (state == 2)
        {
            emit existChanges(*it);
        }
    }
}

bool ChangeTracker::add_file(QString &str)
{
    std::vector<Info*>::iterator it;
    for (it = managers.begin(); it != managers.end(); it++)
    {
        if ((*it)->filePath() == str)
        {
            return false;
        }
    }
    Info *new_manager = new Info(str);
    managers.push_back(new_manager);
    emit addNewFile(new_manager);
    return true;
}

bool ChangeTracker::remove_file(QString &str)
{

    for (int i = 0; i < (int)managers.size(); i++)
    {
        if (managers[i]->filePath() == str)
        {
            emit removeFile(managers[i]);
            delete managers[i];
            managers.erase(std::next(managers.begin(), i));
            return true;
        }
        return false;
    }
}

//void Container::start_tracking(int interval)
//{
//    while (true)
//    {
//        check();
//        std::this_thread::sleep_for( std::chrono::milliseconds( interval ));
//    }
//}

