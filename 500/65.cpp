#include<iostream>
#include<string>

using namespace std;

class BaseAccount
{ 
protected:
    string name, account;
    int balance;
public:
    BaseAccount(string name, string account, int balance)
    {
        this->name = name, this->account = account, this->balance = balance;
    }
    virtual void withdraw(int amount)
    {
        if (this->balance < amount)
        {
            cout << "insufficient" << endl;
            return;
        }
        this->balance -= amount;
    }
    virtual void deposit(int amount)
    {
        this->balance += amount;
    }
    virtual void display()
    {
        cout << this->name << ' '
            << this->account << ' '
            << "Balance:" << this->balance << endl;
    }
};

class BasePlus: public BaseAccount
{
protected:
    int limit = 5000;
    int limitSum = 0;
public:
    using BaseAccount::BaseAccount;
    virtual void withdraw(int amount)
    {
        if (this->limit - this->limitSum + this->balance < amount)
        {
            cout << "insufficient" << endl;
            return;
        }
        int delta = amount - this->balance;
        if (delta < 0)
        {
            this->balance -= amount;
        }
        else
        {
            this->balance = 0;
            this->limitSum += delta;
        }
    };
    virtual void deposit(int amount)
    {
        if (this->limitSum != 0)
        {
            this->limitSum -= amount;
            if (this->limitSum < 0)
            {
                this->balance -= this->limitSum;
                this->limitSum = 0;
            }
        }
        else
        {
            this->balance += amount;
        }
    }
    virtual void display()
    {
        cout << this->name << ' '
            << this->account << ' '
            << "Balance:" << this->balance << ' '
            << "limit:" << this->limit - this->limitSum << endl;
    }
};

int main() {
    int times;
    cin >> times;
    while (times--)
    {
        string name, acc;
        int balance;
        int a, b, c, d;
        cin >> name >> acc >> balance >> a >> b >> c >> d;
        BaseAccount* account;
        if (acc[1] == 'P')
        {
            account = new BasePlus(name, acc, balance);
        }
        else
        {
            account = new BaseAccount(name, acc, balance);
        }
        account->deposit(a);
        account->withdraw(b);
        account->deposit(c);
        account->withdraw(d);
        account->display();
    }
}