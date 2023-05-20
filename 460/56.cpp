#include <iostream>
#include <cmath>

using namespace std;

class Point
{
private:
    double x, y;
public:
    Point(double x, double y)
    {
        this->x = x, this->y = y;
    }
    friend double Distance(Point &a, Point &b);
};

double Distance(Point &a, Point &b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main()
{
    int times;
    cin >> times;
    while (times--)
    {
        double ax, ay, bx, by;
        cin >> ax >> ay >> bx >> by;
        Point *a = new Point(ax, ay), *b = new Point(bx, by);
        cout << (int)Distance(*a, *b) << endl;
    }
    return 0;
}