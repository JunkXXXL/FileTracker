#include "container.h"
#include "console.h"
#include "QDebug"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Widget w;
    //w.show();
    Container& cont = Container::Instance();
    Console& console = Console::Instance();

    QObject::connect(&cont, &Container::noChanges, &console, &Console::messageNoChanges);
    QObject::connect(&cont, &Container::existChanges, &console, &Console::messageExistChanges);
    QObject::connect(&cont, &Container::noFile, &console, &Console::messageNoFile);

    QString str = "C://Users//Lsa32//Desktop//GitLove.txt";
    cont.add_manager(str);
    cont.start_tracking();

    return a.exec();
}
