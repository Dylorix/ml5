#include "mytime.h"
#include <qDebug>

MyTime::MyTime()
    :MyTime(0,0)
{

}

MyTime::MyTime(int hours, int mins)
{
    this->hours = ((hours + mins / MaxMin) % MaxHours);
    this->mins = mins % MaxMin;
}

MyTime::MyTime(char* Ctime)
{
    this->hours = (Ctime[0]-48)*10+(Ctime[1]-48); //Вычитаем 48, т.к. на вход приходят символы, а не числа
    this->mins = (Ctime[3]-48)*10+(Ctime[4]-48);
}

void MyTime::print()
{
    if (mins>=10) //Добавил условие, чтобы не спутать условное "12:05" и "12:50"
        qDebug("%d:%d",hours,mins);
    else
        qDebug("%d:0%d",hours,mins);
}

MyTime MyTime::operator+(int addTime)
{
    return MyTime(hours + (mins + addTime)/MaxMin,(mins + addTime) % MaxMin);
}

int MyTime::operator-(MyTime substr)
{
    return(abs((this->hours*MaxMin+this->mins) - (substr.hours*MaxMin + substr.mins)));
}
