#include "infomodificationobserver.h"

InfoModificationObserver::InfoModificationObserver()
{

}

InfoModificationObserver &InfoModificationObserver::Instance()
{
    static InfoModificationObserver c;

    return c;
}

void InfoModificationObserver::check(bool all_notification)
{
    std::vector<Info*>::iterator it;
    std::vector<Info*> managers = ChangeTracker::Instance().get_contents();
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
