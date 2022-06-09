#include <QCoreApplication>
#include "mytime.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyTime start(15,30), end("17:00");

    int duration = end - start;
    qDebug("%d",duration); //Длительность пары

    (start + duration).print(); //Проверка правильности вычислений

    return a.exec();
}
