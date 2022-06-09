#ifndef MYTIME_H
#define MYTIME_H


class MyTime //Класс назвается "MyTime", а не "Time", т.к. Time уже имеется в std и оно много и долго ругается когда я создаю свой "дубликат".
{
public:
    MyTime();
    MyTime(int mins, int hours);
    MyTime(char* Ctime); //Взял здесь си-шную строку, т.к. с ней удобно работать по индексам
    void print();
    MyTime operator+(int addTime);
    int operator-(MyTime substr);

private:
    int mins,hours; //Время в часах и минутах
    static const int MaxMin = 60, MaxHours = 24; //Константы, через которые нельзя переступать
};

#endif // MYTIME_H
