#ifndef INFO_H
#define INFO_H
#include "QString"
#include "QFileInfo"
#include "QDateTime"

enum class States{
    NO_FILE=0,
    NO_CHANGES,
    EXIST_CHANGES,
    NOTHING_NEW
};

class Info: public QFileInfo
{
public:
    Info(QString file_path);
    States check_changes();

private:
    QDateTime lastChanges;
    States lastState = States::NO_FILE;
};

#endif // INFO_H
