#include<iostream>
#include<cstring>
#include<string>
using namespace std;

class CDate
{
private:
    int year, month, day;
public:
    CDate(int y, int m, int d);
    bool isLeapYear();
    int getYear();
    int getMonth();
    int getDay();
    int getDayofYear();
    int getGap(CDate& date);
};
CDate::CDate(int y, int m, int d)
{
    year = y, month = m, day = d;
}
bool CDate::isLeapYear()
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}
int CDate::getYear()
{
    return year;
}
int CDate::getMonth()
{
    return month;
}
int CDate::getDay()
{
    return day;
}
int CDate::getDayofYear()
{
    return isLeapYear() ? 366 : 365;
}
int CDate::getGap(CDate& date)
{
    int result = 0;
    int a[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    CDate *small, *big;
    if (this->year == date.year)
    {
        if (this->month == date.month)
        {
            small = this->day > date.day ? &date : this;
            big = this->day > date.day ? this : &date;
        }
        else
        {
            small = this->month > date.month ? &date : this;
            big = this->month > date.month ? this : &date;
        }
    }
    else
    {
        small = this->year > date.year ? &date : this;
        big = this->year > date.year ? this : &date;
    }

    for (int i = small->year; i <= big->year; i++)
    {
        auto year = new CDate(i, 1, 1);
        if (year->isLeapYear()) a[2]++;
        result += year->getDayofYear();
        a[2] = 28;
    }
    result -= small->day;
    for (int i = 1; i < small->month; i++)
    {
        result -= a[i];
    }
    a[2] = 28;
    if (big->isLeapYear())
    {
        a[2]++;
    }
    result -= a[big->month] - big->day;
    for (int i = big->month + 1; i <= 12; i++)
    {
        result -= a[i];
    }
    return this != small ? result : -result;
}

class Software
{
public:
    Software(string name, char type, CDate* date, char media)
    {
        this->name = name;
        this->type = type;
        this->date = date;
        this->media = media;
    }
    Software(const Software& origin)
    {
        this->name = origin.name;
        this->type = 'B';
        this->date = origin.date;
        this->media = 'H';
    }
    void print()
    {
        cout << "name:" << this->name << endl;
        cout << "type:";
        if (this->type == 'O')
            cout << "original" << endl;
        else if (this->type == 'T')
            cout << "trial" << endl;
        else if (this->type == 'B')
            cout << "backup" << endl;

        cout << "media:";
        if (this->media == 'D')
            cout << "optical disk" << endl;
        else if (this->media == 'H')
            cout << "hard disk" << endl;
        else if (this->media == 'U')
            cout << "USB disk" << endl;

        if (this->date->getYear() == 0)
        {
            cout << "this software has unlimited use" << endl;
        }
        else
        {
            int daysToExpire = this->date->getGap(*new CDate(2015, 4, 8));
            if (daysToExpire < 0)
            {
                cout << "this software has expired" << endl;
            }
            else
            {
                cout << "this software is going to be expired in " << daysToExpire << " days" << endl;
            }
        }
        cout << endl;
    }
private:
    string name;
    char type;
    CDate* date;
    char media;
};

int main()
{
    int times;
    cin >> times;
    while (times--)
    {
        string name;
        char type, media;
        int y, m, d;
        cin >> name >> type >> media >> y >> m >> d;
        auto soft = new Software(name, type, new CDate(y, m, d), media);
        auto copy = new Software(*soft);
        soft->print();
        copy->print();
    }
    return 0;
}