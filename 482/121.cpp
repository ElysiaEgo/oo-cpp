#include<iostream>
using namespace std;

enum AccountType
{
    P = 'P',
    E = 'E'
};

class Account
{
    private:
    double balance;
    float interest;
    int number;
    AccountType type;
    public:
    Account(int number, AccountType type, double balance)
    {
        this->number = number;
        this->type = type;
        this->balance = balance;
        this->interest = 0.005;
    }
    Account(const Account& another)
    {
        this->number = another.number;
        this->type = another.type;
        this->balance = another.balance;
        this->interest = 0.015;
        this->number += 50000000;
    }
    void query()
    {
        cout << "Account=" << this->number
        << "--" << (this->type == AccountType::P ? "Person" : "Enterprise")
        << "--sum=" << this->balance
        << "--rate=" << this->interest << endl;
    }
    void calc()
    {
        this->balance += this->balance * this->interest;
        cout << "Account=" << this->number
        << "--sum=" << this->balance << endl;
    }
};

int main() {
    int times;
    cin >> times;
    while (times--)
    {
        int number;
        char type;
        double balance;
        cin >> number >> type >> balance;
        auto acc = Account(number, (AccountType) type, balance);
        auto acc2 = Account(acc);
        char a, b;
        cin >> a >> b;
        if (a == 'C')
        {
            acc.calc();
        } else
        {
            acc.query();
        }
        if (b == 'C')
        {
            acc2.calc();
        } else
        {
            acc2.query();
        }
    }
    return 0;
}