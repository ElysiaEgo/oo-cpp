#include <iostream>
#include <string>

using namespace std;

class Complex
{
private:
    double real; // 实部
    double imag; // 虚部
public:
    Complex() {}
    Complex(double r, double i)
    {
        this->real = r, this->imag = i;
    }
    // 友元函数，复数c1 + c2(二参数对象相加)
    friend Complex addCom(const Complex& c1, const Complex& c2);
    friend Complex minusCom(const Complex& c1, const Complex& c2);
    // 友元函数，输出类对象c的有关数据(c为参数对象)
    friend void outCom(const Complex& c);
};

Complex addCom(const Complex& c1, const Complex& c2)
{
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

Complex minusCom(const Complex& c1, const Complex& c2)
{
    return Complex(c1.real - c2.real, c1.imag - c2.imag);
}

void outCom(const Complex& c)
{
    cout << '(' << c.real << ',' << c.imag << ')' << endl;
}

int main()
{
    double r, i;
    cin >> r >> i;
    auto com = Complex(r, i);
    int times;
    cin >> times;
    while (times--)
    {
        char op;
        double r, i;
        cin >> op >> r >> i;
        if (op == '+')
        {
            com = addCom(com, Complex(r, i));
        }
        else
        {
            com = minusCom(com, Complex(r, i));
        }
        outCom(com);
    }
    return 0;
}