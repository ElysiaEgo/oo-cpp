#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class CPeople
{
protected:
    string name;
    string id;
public:
    CPeople(string n, string i):name(n), id(i){}
    void print()
    {
        cout << "Name: " << name << " ID: " << id << endl;
    }
};
class CBankCustomer: public CPeople
{
protected:
    double balance;
public:
    CBankCustomer(string n, string i, double b):CPeople(n, i), balance(b) {}
    void deposit(double money)
    {
        balance += money;
    }
    int withdraw(double money)
    {
        if(balance < money)
            return 0;
        else
        {
            balance -= money;
            return 1;
        }
    }
    void print()
    {
        CPeople::print();
        cout << "Bank balance: " << balance << endl;
    }
};
class CInternetBankCustomer:public CBankCustomer
{
private:
    string password;
    double balance = 0;
    double interest;
public:
    CInternetBankCustomer(string n, string i, string p, double b):CBankCustomer(n, i, b), password(p){}
    void registerUser(string n, string i, string p)
    {
        name = n;
        id = i;
        password = p;
    }
    void openAccount(string n, string i)
    {
        name = n;
        id = i;
    }
    int login(string i, string p)
    {
        if(id == i && password == p)
            return 1;
        else
            return 0;
    }
    void setInterest(double i)
    {
        interest = i;
    }
    void calculateProfit()
    {
        balance += balance * interest / 10000;
    }
    int deposit(double money)
    {
        if (CBankCustomer::withdraw(money) == 1) {
            balance += money;
            return 1;
        }
        return 0;
    }
    int withdraw(double money)
    {
        if(balance < money)
            return 0;
        else
        {
            balance -= money;
            CBankCustomer::deposit(money);
            return 1;
        }
    }
    void print()
    {
        CBankCustomer::print();
        cout << "Internet bank balance: " << balance << endl;
    }
};

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        string i_xm, i_id, i_mm, b_xm, b_id, ib_id, ib_mm;
        double money, interest;
        int no_of_days, i;
        char op_code;
        cin >> i_xm >> i_id >> i_mm;
        cin >> b_xm >> b_id;
        cin >> ib_id >> ib_mm;
        CInternetBankCustomer ib_user(i_xm, i_id, i_mm, 0);
        ib_user.openAccount(b_xm, b_id);
        if(ib_user.login(ib_id, ib_mm) == 0)
        {
            cout << "Password or ID incorrect" << endl;
            continue;
        }
        cin >> no_of_days;
        for(i = 0; i < no_of_days; i++)
        {
            cin >> op_code >> money >> interest;
            switch(op_code)
            {
            case 'S':
            case 's':
                if(ib_user.deposit(money) == 0)
                {
                    cout << "Bank balance not enough" << endl;
                    continue;
                }
                break;
            case 'T':
            case 't':
                if(ib_user.withdraw(money) == 0)
                {
                    cout << "Internet bank balance not enough" << endl;
                    continue;
                }
                break;
            case 'D':
            case 'd':
                ib_user.CBankCustomer::deposit(money);
                break;
            case 'W':
            case 'w':
                if(ib_user.CBankCustomer::withdraw(money) == 0)
                {
                    cout << "Bank balance not enough" << endl;
                    continue;
                }
                break;
            default:
                cout << "Illegal input" << endl;
                continue;
            }
            ib_user.print();
            ib_user.setInterest(interest);
            ib_user.calculateProfit();
            cout << endl;
        }
    }
    return 0;
}
