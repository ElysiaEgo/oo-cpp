#include<iostream>
#include<string>

using namespace std;

class CAccount {
    public:
        long account;
        string name;
        float balance;
        void deposit(float value) {
            this->balance += value;
            cout << "saving ok!"<< endl;
        }
        void withdraw(float value) {
            if (this->balance > value) {
                this->balance -= value;
                cout << "withdraw ok!"<< endl;
            } else {
                cout << "sorry! over limit!"<< endl;
            }
        }
        void check() {
            cout << this->name << "'s balance is " << this->balance << endl;
        }
};

int main() {
    int times = 2;
    while (times--) {
        auto a = new CAccount();
        float temp;
        cin >> a->account >> a->name >> a->balance;
        a->check();
        cin >> temp;
        a->deposit(temp);
        a->check();
        cin >> temp;
        a->withdraw(temp);
        a->check();
    }
}
