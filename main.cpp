#include "container.h"
#include "console.h"
#include "QDebug"

#include <QApplication>

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
    Container& cont = Container::Instance();
    Console& console = Console::Instance();


    qDebug() << "1) Ввели дважды один файл";
    QString str = "C://Users//Lsa32//Desktop//a.txt";
    cont.add_file(str);
    cont.add_file(str);
    //cont.
    //cont.remove_manager(str);
    //cont.remove_manager(str);
    //cont.start_tracking();
    //QString qwer = "ASD";
    //qDebug() << cont.remove_manager(qwer);
    return 0;
    //return a.exec();
}
