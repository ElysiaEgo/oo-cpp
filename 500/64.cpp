#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

class Shape
{
public:
    Shape() = default;
    virtual double area() = 0;
};

class Circle: public Shape
{
    private:
    double r;
    public:
    Circle(double r): Shape()
    {
        this->r = r;
    }
    double area()
    {
        return 3.14 * r * r;
    }
};
class Square: public Shape
{
    private:
    double a;
    public:
    Square(double a): Shape()
    {
        this->a = a;
    }
    double area()
    {
        return a * a;
    }
};
class Rectangle: public Shape
{
    private:
    double a, b;
    public:
    Rectangle(double a, double b): Shape()
    {
        this->a = a, this->b = b;
    }
    double area()
    {
        return a * b;
    }
};

int main() {
    int times;
    cin >> times;
    while (times--)
    {
        double r, a, b, c;
        cin >> r >> a >> b >> c;
        auto shapes = new Shape*[3];
        shapes[0] = new Circle(r);
        shapes[1] = new Square(a);
        shapes[2] = new Rectangle(b, c);
        for (int i = 0; i < 3; i++)
        {
            cout << fixed << setprecision(2) << shapes[i]->area() << endl;
        }
    }
}