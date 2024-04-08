#ifndef INFOMODIFICATIONOBSERVER_H
#define INFOMODIFICATIONOBSERVER_H

#include <QObject>
#include "info.h"
#include "ChangeTracker.h"

class InfoModificationObserver
{
    Q_OBJECT
private:
    InfoModificationObserver();
    ~InfoModificationObserver();
public:
    static InfoModificationObserver& Instance();
    void check(bool all_notification = false);
    InfoModificationObserver(InfoModificationObserver const&);
    InfoModificationObserver& operator= (InfoModificationObserver const&);
signals:
    void noFile(Info* current);
    void noChanges(Info* current);
    void existChanges(Info* current);
};

#endif // INFOMODIFICATIONOBSERVER_H
