#include<iostream>
#include<string>

using namespace std;

class CDate
{
private:
    int year, month, day;
public:
    CDate() {};
    CDate(int y, int m, int d);
    CDate(const CDate& date);
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
CDate::CDate(const CDate& date)
{
    year = date.year, month = date.month, day = date.day;
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

class Student
{
private:
    CDate birth;
    string name;
public:
    Student() {};
    Student(int y, int m, int d, string name): birth(y, m, d), name(name) {};
    Student(const Student&);
    string getName() { return name; }
    int operator-(Student&);
};

Student::Student(const Student& s)
{
    birth = s.birth;
    name = s.name;
}

int Student::operator-(Student& s)
{
    return birth.getGap(s.birth);
}

int main()
{
    int nums;
    cin >> nums;
    auto students = new Student[nums];
    for (int i = 0; i < nums; i++)
    {
        int y, m, d;
        string name;
        cin >> name >> y >> m >> d;
        students[i] = Student(y, m, d, name);
    }
    int maxGap = 0;
    int max1 = 0, max2 = 0;
    for (int i = 0; i < nums; i++)
    {
        for (int j = i + 1; j < nums; j++)
        {
            int gap = abs(students[i] - students[j]);
            if (gap > maxGap)
            {
                maxGap = gap;
                max1 = i;
                max2 = j;
            }
        }
    }
    cout << students[min(max1, max2)].getName() << "和" << students[max(max1, max2)].getName() << "年龄相差最大，为" << abs(students[max1] - students[max2]) << "天。" << endl;
    return 0;
}
