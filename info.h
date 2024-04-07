#ifndef INFO_H
#define INFO_H
#include "QString"
#include "QFileInfo"
#include "QDateTime"

enum class States{
    NO_FILE=0,
    NO_CHANGES,
    EXIST_CHANGES
};

class Info
{
public:
    Info(QString file_path);
    States check_changes();
    QString getName() const;
    QDateTime getTimeChanging();
    QString get_filePath();

private:
    QString filePath;
    QDateTime lastChanges;
    QFileInfo fileInfo;
};

#endif // INFO_H
