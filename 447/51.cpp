#include<iostream>
#include<cstring>
#include<string>

using namespace std;

class CTelNumber
{
public:
    CTelNumber(const char* num)
    {
        this->number = new char[8];
        strcpy(this->number, num);
    }
    CTelNumber(const CTelNumber& number)
    {
        this->number = new char[9];
        if (number.number[0] == '2'
            || number.number[0] == '3'
            || number.number[0] == '4')
            this->number[0] = '8';
        if (number.number[0] == '5'
            || number.number[0] == '6'
            || number.number[0] == '7'
            || number.number[0] == '8')
            this->number[0] = '2';
        strcpy(this->number + 1, number.number);
    }
    ~CTelNumber()
    {
        delete this->number;
    }
    void print()
    {
        cout << this->number << endl;
    }
private:
    char* number;
};

int main()
{
    int times;
    cin >> times;
    while (times--)
    {
        string tmp;
        cin >> tmp;
        auto num = tmp.c_str();
        if (strlen(num) != 7)
        {
            cout << "Illegal phone number" << endl;
            continue;
        }
        bool legal = false;
        if (num[0] == '2'
            || num[0] == '3'
            || num[0] == '4')
            legal = true;
        if (num[0] == '5'
            || num[0] == '6'
            || num[0] == '7'
            || num[0] == '8')
            legal = true;
        if (!legal)
            cout << "Illegal phone number" << endl;
        for (int i = 0; i < 7; i++)
        {
            if (num[i] > '9' || num[i] < '0')
            {
                cout << "Illegal phone number" << endl;
                legal = false;
                break;
            }
        }
        if (legal) (new CTelNumber(*new CTelNumber(num)))->print();
    }
    return 0;
}