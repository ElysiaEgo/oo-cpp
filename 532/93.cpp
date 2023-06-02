#include<iostream>

using namespace std;

class CClock
{
private:
    int hour;
    int minute;
    int second;
public:
    CClock(int hour, int minute, int second)
    {
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }
    CClock(const CClock& another)
    {
        hour = another.hour;
        minute = another.minute;
        second = another.second;
    }
    CClock operator++()
    {
        second++;
        if (second == 60)
        {
            second = 0;
            minute++;
            if (minute == 60)
            {
                minute = 0;
                hour++;
                if (hour == 12)
                {
                    hour = 0;
                }
            }
        }
        return *this;
    }
    CClock operator--()
    {
        second--;
        if (second == -1)
        {
            second = 59;
            minute--;
            if (minute == -1)
            {
                minute = 59;
                hour--;
                if (hour == -1)
                {
                    hour = 11;
                    minute = 59;
                    second = 59;
                }
            }
        }
        return *this;
    }
    void print()
    {
        cout << hour << ":" << minute << ":" << second << endl;
    }
};

int main()
{
    int h, m, s;
    cin >> h >> m >> s;
    CClock clock(h, m, s);
    int times;
    cin >> times;
    while (times--)
    {
        int op;
        cin >> op;
        if (op > 0)
        {
            while (op--)
            {
                ++clock;
            }
        }
        else
        {
            while (op++)
            {
                --clock;
            }
        }
        clock.print();
    }
}