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

    QString str = "C://Users//Lsa32//Desktop//a.txt";
    QString str1 = "C://Users//Lsa32//Desktop//b.txt";
    QString str2 = "C://Users//Lsa32//Desktop//egor.jpg";
    cont.add_manager(str);
    cont.add_manager(str1);
    cont.add_manager(str2);
    cont.remove_manager(str);
    cont.remove_manager(str);
    cont.start_tracking();
    //QString qwer = "ASD";
    //qDebug() << cont.remove_manager(qwer);

    return a.exec();
}
