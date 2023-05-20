#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

class Point
{
    double x, y;
public: 
    Point() {};
    Point(double _x, double _y)
    {
        this->x = _x, this->y = _y;
    }
    double getX()
    {
        return this->x;
    }
    double getY()
    {
        return this->y;
    }
    void setX(double _x)
    {
        this->x = _x;
    }
    void setY(double _y)
    {
        this->y = _y;
    }
    double distanceToAnotherPoint(Point& p) {
        return sqrt(pow(this->x - p.getX(), 2) + pow(this->y - p.getY(), 2));
    }
};

int main()
{
    cout << fixed << setprecision(2);
    int times;
    cin >> times;
    while (times--)
    {
        double a, b, c, d;
        cin >> a >> b >> c >> d;
        auto pA = new Point(a, b), pB = new Point(c, d);
        cout << "Distance of Point("<< pA->getX() << "," << pA->getY() << ") to Point(" << pB->getX() << "," << pB->getY() << ") is " << pA->distanceToAnotherPoint(*pB) << endl;
    }
    return 0;
}