#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

class Time;

class Date
{
private:
    int y, m, d;
public:
    Date(int y, int m, int d)
    {
        this->y = y, this->m = m, this->d = d;
    }
    friend void display(const Date &d, const Time &t);
};

class Time
{
private:
    int h, m, s;
public:
    Time(int h, int m, int s)
    {
        this->h = h, this->m = m, this->s = s;
    }
    friend void display(const Date &d, const Time &t);
};

void display(const Date &d, const Time &t)
{
    cout << setfill('0') << setw(4)
    << d.y << '-' << setw(2) << d.m << '-' << setw(2) << d.d << ' '
    << setw(2) << t.h << ':' << setw(2) << t.m << ':' << setw(2) << t.s << endl;
}

int main()
{
    int times;
    cin >> times;
    while (times--)
    {
        int y, dm, d;
        int h, tm, s;
        cin >> y >> dm >> d >> h >> tm >> s;
        display(Date(y, dm, d), Time(h, tm, s));
    }
    return 0;
}