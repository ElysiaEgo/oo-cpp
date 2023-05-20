#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

int monthLength[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

class Date
{
    int y, m, d;
public:
    Date();
    Date(int _y, int _m, int _d);
    int getYear();
    int getMonth();
    int getDay();
    void setDate(int _y, int _m, int _d);
    void print();
    void addOneDay();
};

Date::Date() {};
Date::Date(int _y, int _m, int _d)
{
    this->y = _y;
    this->m = _m;
    this->d = _d;
}
int Date::getYear()
{
    return this->y;
}
int Date::getMonth()
{
    return this->m;
}
int Date::getDay()
{
    return this->d;
}
void Date::setDate(int _y, int _m, int _d)
{
    this->y = _y;
    this->m = _m;
    this->d = _d;
}
void Date::print()
{
    cout << setfill('0') << setw(2) << this->y << '/' << setfill('0') << setw(2) << this->m << '/' << setfill('0') << setw(2) << this->d << endl;
}
void Date::addOneDay()
{
    this->d++;
    if (this->y % 4 == 0 && this->y % 100 != 0 || this->y % 400 == 0)
        monthLength[1] = 29;
    else
        monthLength[1] = 28;
    if (this->d > monthLength[this->m - 1]) {
        this->d = 1;
        this->m++;
    }
    if (this->m > 12) {
        this->m = 1;
        this->y++;
    }
}

int main()
{
    int times;
    cin >> times;
    while (times--)
    {
        int y, m, d;
        cin >> y >> m >> d;
        auto date = new Date(y, m, d);
        cout << "Today is ";
        date->print();
        date->addOneDay();
        cout << "Tomorrow is ";
        date->print();
    }
    return 0;
}