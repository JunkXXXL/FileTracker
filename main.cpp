#include "container.h"
#include "console.h"
#include "QDebug"
#include "info.h"
#include "QFile"
#include <fstream>
#include <iostream>

#include <QApplication>

void testing(QString& direct)
{
    Container& cont = Container::Instance();
    Console& console = Console::Instance();
    QString str = direct + "a.txt";
    std::ofstream file_a(str.toStdString());
    file_a.close();


    qDebug() << "1) Ввели дважды один файл";
    cont.add_file(str);
    cont.add_file(str);

    qDebug() << "\n2) Попытаемся удалить один и тот же файл дважды";
    cont.remove_file(str);
    cont.remove_file(str);

    qDebug() << "\n3) Проверка, файл не изменялся после добавления";
    cont.add_file(str);
    cont.check(false);

    qDebug() << "\n4) Проверка, файл изменился";
    std::ofstream of(str.toStdString());
    if (of.is_open())
    {
        of << "a";
        of.close();
        cont.check(false);
    }
    else
    {
        qDebug() << "Не удалось открыть файл.";
    }

    qDebug() << "\n5) Удалим файл и попробуем его проверить";
    QFile fl(str);
    if (fl.remove())
    {
        cont.check(false);
    }
    else
    {
        qDebug() << "Не удалось удалить файл";
    }
}

void tracking(QString& dir, int interval)
{
    QString afl = dir + "a.txt";
    QString bfl = dir + "b.txt";
    QString cfl = dir + "c.txt";
    Container& cont = Container::Instance();
    Console& cons = Console::Instance();

    std::ofstream file_a(afl.toStdString());
    file_a.close();
    std::ofstream file_b(bfl.toStdString());
    file_a.close();
    std::ofstream file_c(cfl.toStdString());
    file_a.close();

    if (!cont.add_file(bfl) or !cont.add_file(afl) or !cont.add_file(cfl))
    {
        qDebug() << "Не удалось добавить файлы";
        return;
    }

    while (true)
    {
        cons.printCurrentTime();
        cont.check();
        std::this_thread::sleep_for( std::chrono::milliseconds( interval ));
    }
}

int main(int argc, char *argv[])
{
    QString dir = "C://Users//Lsa32//Desktop//";
    //testing(dir);
    tracking(dir, 500);

    return 0;
}
