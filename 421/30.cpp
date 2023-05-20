#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
#include<vector>

using namespace std;

//-----类定义------
class Point
{
    public:
    double x, y;
    void setPoint(double x, double y);
    double getX();
    double getY();
};

class Circle
{
    public:
    double x, y, r;
    void setCenter(double x, double y);
    void setRadius(double r);
    double getArea();
    double getLength();
    bool contain(Point p);
};

//----类实现------
void Point::setPoint(double x, double y)
{
    this->x = x, this->y = y;
};
double Point::getX()
{
    return this->x;
};
double Point::getY()
{
    return this->y;
};

void Circle::setCenter(double x, double y) {
    this->x = x, this->y = y;
}
void Circle::setRadius(double r) {
    this->r = r;
}
double Circle::getArea() {
    return this->r * this->r * 3.14;
}
double Circle::getLength() {
    return this->r * 3.14 * 2;
}
bool Circle::contain(Point p) {
    double deltaX = this->x > p.getX() ? this->x - p.getX() : p.getX() - this->x;
    double deltaY = this->y > p.getY() ? this->y - p.getY() : p.getY() - this->y;
    double distance = sqrt(deltaY * deltaY + deltaX * deltaX * deltaX);
    if (distance > this->r) {
        return false;
    }
    return true;
}

//-----主函数-----
int main()
{
    vector<Point *> points;
    points.push_back(new Point());
    points[0]->getX();
    //自定义一些变量
    double x, y, r;
    //创建一个圆对象和一个点对象
    auto cir = new Circle();
    auto point = new Point();
    //输入圆对象和点对象的属性数值，并做初始化
    cin >> x >> y >> r;
    cir->setCenter(x, y);
    cir->setRadius(r);
    cin >> x >> y;
    point->setPoint(x, y);
    //输出圆的面积和圆的周长
    cout << fixed << setprecision(2) << cir->getArea() << ' ' << cir->getLength() << endl;
    //输出圆是否包含点，包含则输出yes，否则输出no
    cout << (cir->contain(*point) ? "yes" : "no") << endl;
    return 0;
}
