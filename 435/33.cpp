#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

int gcd(int a, int b)
{
    return b > 0 ? gcd(b, a % b) : a;
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

class CFraction
{
    int fz, fm;
public:
    CFraction();
    CFraction(int _fz, int _fm);
    CFraction add(const CFraction& r);
    CFraction sub(const CFraction& r);
    CFraction mul(const CFraction& r);
    CFraction div(const CFraction& r);
    int getGCD();
    void print();
};

CFraction::CFraction() {};
CFraction::CFraction(int _fz, int _fm)
{
    this->fz = _fz, this->fm = _fm;
}
CFraction CFraction::add(const CFraction& r)
{
    auto newFm = this->fm * r.fm;
    auto newFz = this->fz * r.fm + r.fz * this->fm;
    auto result = new CFraction(newFz, newFm);
    auto gcd = result->getGCD();
    result->fz /= gcd;
    result->fm /= gcd;
    return *result;
}
CFraction CFraction::sub(const CFraction& r)
{
    auto newFm = this->fm * r.fm;
    auto newFz = this->fz * r.fm - r.fz * this->fm;
    auto result = new CFraction(newFz, newFm);
    auto gcd = result->getGCD();
    result->fz /= gcd;
    result->fm /= gcd;
    return *result;
}
CFraction CFraction::mul(const CFraction& r)
{
    auto newFz = this->fz * r.fz;
    auto newFm = this->fm * r.fm;
    auto result = new CFraction(newFz, newFm);
    auto gcd = result->getGCD();
    result->fz /= gcd;
    result->fm /= gcd;
    return *result;
}
CFraction CFraction::div(const CFraction& r)
{
    auto newFz = this->fz * r.fm;
    auto newFm = this->fm * r.fz;
    auto result = new CFraction(newFz, newFm);
    auto gcd = result->getGCD();
    result->fz /= gcd;
    result->fm /= gcd;
    return *result;
}
int CFraction::getGCD()
{
    return gcd(this->fz > 0 ? this->fz : -this->fz, this->fm > 0 ? this->fm : this->fm);
}
void CFraction::print()
{
    cout << this->fz << '/' << this->fm << endl;
}

int main()
{
    int times;
    cin >> times;
    while (times--)
    {
        int fza, fma, fzb, fmb;
        cin >> fza;
        cin.get();
        cin >> fma;
        cin >> fzb;
        cin.get();
        cin >> fmb;
        auto a = *new CFraction(fza, fma);
        auto b = *new CFraction(fzb, fmb);
        a.add(b).print();
        a.sub(b).print();
        a.mul(b).print();
        a.div(b).print();
        cout << endl;
    }
    return 0;
}