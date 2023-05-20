#include <iostream>
#include <string>

using namespace std;

class Account
{
private:
    static float count;
    static float interestRate;
    string accno, accname;
    float balance;
public:
    Account(string ac, string na, float ba)
    {
        this->accno = ac, this->accname = na, this->balance = ba;
        count += ba;
    }
    ~Account()
    {}
    void deposit(float amount)
    {
        this->balance += amount;
        count += amount;
    }
    void withdraw(float amount)
    {
        this->balance -= amount;
        count -= amount;
    }
    float getBalance()
    {
        return this->balance;
    }
    void show()
    {
        cout << this->accno << ' ' << this->accname;
    }
    static float getCount()
    {
        return count;
    }
    static void setInterestRate(float rate)
    {
        interestRate = rate;
    }
    static float getInterestRate()
    {
        return interestRate;
    }
    friend void update(Account& a);
};

float Account::count = 0;
float Account::interestRate = 0;

void update(Account& a)
{
    a.deposit(a.balance * Account::interestRate);
}

int main()
{
    float rate;
    cin >> rate;
    Account::setInterestRate(rate);
    int times;
    cin >> times;
    while (times--)
    {
        string ac, na;
        cin >> ac >> na;
        float balance, deposit, withdraw;
        cin >> balance >> deposit >> withdraw;
        auto acc = new Account(ac, na, balance);
        acc->show();
        acc->deposit(deposit);
        cout << ' ' << acc->getBalance();
        update(*acc);
        cout << ' ' << acc->getBalance();
        acc->withdraw(withdraw);
        cout << ' ' << acc->getBalance() << endl;
        delete acc;
    }
    cout << Account::getCount() << endl;
    return 0;
}