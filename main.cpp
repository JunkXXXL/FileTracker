#include "widget.h"
#include "container.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Widget w;
    //w.show();
    Container& cont = Container::Instance();
    QString str = "C://Users//Lsa32//Desktop//GitLove.txt";
    cont.add_manager(str);
    cont.start_tracking();
    return a.exec();
}
