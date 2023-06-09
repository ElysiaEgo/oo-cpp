#include<iostream>

using namespace std;

class Complex
{
private:
    float real, image;
public:
    Complex(float x = 0, float y = 0);
    friend Complex operator+(Complex&, Complex&);
    friend Complex operator-(Complex&, Complex&);
    friend Complex operator*(Complex&, Complex&);
    void show();
};

Complex::Complex(float x, float y)
{
    real = x;
    image = y;
}

Complex operator+(Complex& c1, Complex& c2)
{
    Complex temp;
    temp.real = c1.real + c2.real;
    temp.image = c1.image + c2.image;
    return temp;
}

Complex operator-(Complex& c1, Complex& c2)
{
    Complex temp;
    temp.real = c1.real - c2.real;
    temp.image = c1.image - c2.image;
    return temp;
}

Complex operator*(Complex& c1, Complex& c2)
{
    Complex temp;
    temp.real = c1.real * c2.real - c1.image * c2.image;
    temp.image = c1.real * c2.image + c1.image * c2.real;
    return temp;
}

void Complex::show()
{
    cout << "Real=" << real << " Image=" << image << endl;
}

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    Complex c1(a, b), c2(c, d), c3;
    c3 = c1 + c2;
    c3.show();
    c3 = c1 - c2;
    c3.show();
    c3 = c1 * c2;
    c3.show();
    return 0;
}