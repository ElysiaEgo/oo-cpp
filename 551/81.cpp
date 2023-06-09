#include<iostream>

using namespace std;

class Point
{
private:
    int x, y, z;
public:
    Point(int x=0, int y=0, int z=0) { this->x = x; this->y = y; this->z = z; }
    friend Point operator++(Point&);
    friend Point operator++(Point&, int);
    friend Point operator--(Point&);
    friend Point operator--(Point&, int);
    void show() { cout << "x=" << x << " y=" << y << " z=" << z << endl; }
};

Point operator++(Point& p)
{
    p.x++;
    p.y++;
    p.z++;
    return p;
}

Point operator++(Point& p, int)
{
    Point temp = p;
    p.x++;
    p.y++;
    p.z++;
    return temp;
}

Point operator--(Point& p)
{
    p.x--;
    p.y--;
    p.z--;
    return p;
}

Point operator--(Point& p, int)
{
    Point temp = p;
    p.x--;
    p.y--;
    p.z--;
    return temp;
}

int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    Point p1(x, y, z), p2;
    p2 = p1++;
    p1.show();
    p2.show();
    --p1;
    p2 = ++p1;
    p1.show();
    p2.show();
    --p1;
    p2 = p1--;
    p1.show();
    p2.show();
    ++p1;
    p2 = --p1;
    p1.show();
    p2.show();
    return 0;
}