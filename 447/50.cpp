#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

class Number
{
public:
    Number()
    {
        this->num = 0;
        cout << "Constructed by default, value = " << this->num << endl;
    }
    Number(int num)
    {
        this->num = num;
        cout << "Constructed using one argument constructor, value = " << this->num << endl;
    }
    Number(const Number& num)
    {
        this->num = num.num;
        cout << "Constructed using copy constructor, value = " << this->num << endl;
    }
private:
    int num;
};

int main()
{
    int times;
    cin >> times;
    while (times--)
    {
        int type;
        cin >> type;
        if (type == 0) {
            *new Number();
        }
        else if (type == 1) {
            int tmp;
            cin >> tmp;
            *new Number(tmp);
        }
        else {
            int tmp;
            cin >> tmp;
            *new Number(*new Number(tmp));
        }
    }
    return 0;
}