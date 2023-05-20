#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

class Equation
{
public:
    Equation()
    {
        this->a = 1, this->b = 1, this->c = 0;
    }
    Equation(double a, double b, double c)
    {
        this->a = a, this->b = b, this->c = c;
    }
    void set(double a, double b, double c)
    {
        this->a = a, this->b = b, this->c = c;
    }
    void getRoot()
    {
        auto delta = pow(this->b, 2) - 4 * this->a * this->c;
        if (delta > 0)
        {
            auto x1 = (-this->b + sqrt(delta)) / (2 * this->a);
            auto x2 = (-this->b - sqrt(delta)) / (2 * this->a);
            cout << "x1=" << fixed << setprecision(2) << x1
                << " x2=" << fixed << setprecision(2) << x2 << endl;
        } else if (delta < 0)
        {
            auto xa = (-this->b) / (2 * this->a);
            auto xb = sqrt(-delta) / (2 * this->a);
            cout << "x1=" << fixed << setprecision(2) << xa
                << "+" << fixed << setprecision(2) << xb << "i "
                << "x2=" << fixed << setprecision(2) << xa
                << "-" << fixed << setprecision(2) << xb << "i" << endl;
        }
        else {
            auto x = (-this->b) / (2 * this->a);
            cout << "x1=x2=" << fixed << setprecision(2) << x << endl;
        }
    }
private:
    double a, b, c;
};

int main()
{
    int times;
    cin >> times;
    while (times--)
    {
        double a, b, c;
        cin >> a >> b >> c;
        auto equ = new Equation(a, b, c);
        equ->getRoot();
    }
    return 0;
}