#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

class Date
{
private:
    int year;
    int month;
    int day;
public:
    Date(int year, int month, int day)
    {
        this->year = year;
        this->month = month;
        this->day = day;
    }
    void print()
    {
        cout << this->year << '.'
            << this->month << '.'
            << this->day;
    }
};

class Phone
{
public:
    Phone(const Phone &another)
    {
        this->type = another.type;
        this->number = another.number;
        this->status = another.status;
        this->suspend = another.suspend;
        cout << "Construct a copy of phone " << this->number << endl;
    }
    Phone(char type, string number, int status)
    {
        this->type = type;
        this->number = number;
        this->status = status;
        this->suspend = nullptr;
        cout << "Construct a new phone " << this->number << endl;
    }
    void print()
    {
        string types[] = {
            "机构",
            "企业",
            "个人",
            "备份"
        };
        string states[] = {
            "在用",
            "未用",
            "停用"
        };
        cout << "类型=" << types[this->type - 'A']
            << "||号码=" << this->number
            << "||State=" << states[this->status - 1];
        if (this->status == 3 && this->suspend != nullptr)
        {
            cout << "||停机日期=";
            this->suspend->print();
        }
        cout << endl;
    }
    void stop(int year, int month, int day)
    {
        cout << "Stop the phone " << this->number << endl;
        this->suspend = new Date(year, month, day);
        this->status = 3;
    }
    string getNumber()
    {
        return this->number;
    }
    void setNumber(string number)
    {
        this->number = number;
    }
    void setType(char type)
    {
        this->type = type;
    }
    ~Phone()
    {
        delete this->suspend;
    }
private:
    char type;
    string number;
    int status;
    Date *suspend;
};

int main()
{
    int times;
    cin >> times;
    while (times--)
    {
        char type;
        string number;
        int status, year, month, day;
        cin >> type >> number >> status >> year >> month >> day;
        auto phone = new Phone(type, number, status);
        // if (status == 3) phone->stop(year, month, day);
        phone->print();
        auto newPhone = new Phone(*phone);
        newPhone->setNumber(newPhone->getNumber() + 'X');
        newPhone->setType('D');
        newPhone->print();
        phone->stop(year, month, day);
        phone->print();
        cout << "----" << endl;
        delete phone, newPhone;
    }
    return 0;
}