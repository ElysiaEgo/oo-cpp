#include<iostream>

using namespace std;

class CPoint
{
private:
    int x;
    int y;
public:
    CPoint(int x1, int y1)
    {
        x = x1;
        y = y1;
    }
    CPoint(const CPoint& another)
    {
        x = another.x;
        y = another.y;
    }
    int getX() const
    {
        return x;
    }
    int getY() const
    {
        return y;
    }
};

class CRectangle
{
private:
    CPoint leftUp;
    CPoint rightDown;
public:
    CRectangle(int x1, int y1, int x2, int y2):leftUp(x1, y1), rightDown(x2, y2)
    {
    }
    CRectangle(const CRectangle& another):leftUp(another.leftUp), rightDown(another.rightDown)
    {
    }
    bool operator==(const CRectangle& another)
    {
        if (leftUp.getX() == another.leftUp.getX()
            && leftUp.getY() == another.leftUp.getY()
            && rightDown.getX() == another.rightDown.getX()
            && rightDown.getY() == another.rightDown.getY())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator>(const CRectangle& another)
    {
        if (another.leftUp.getX() >= leftUp.getX()
            && leftUp.getY() >= another.leftUp.getY()
            && another.rightDown.getX() <= rightDown.getX()
            && rightDown.getY() <= another.rightDown.getY())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int operator<(const CRectangle& another)
    {
        return !(*this > another);
    }
    operator int()
    {
        return -(rightDown.getX() - leftUp.getX()) * (rightDown.getY() - leftUp.getY());
    }
    friend ostream& operator<<(ostream& os, const CRectangle& rect);
    friend bool operator*(const CRectangle& rect1, const CRectangle& rect2);
};

ostream& operator<<(ostream& os, const CRectangle& rect)
{
    os << rect.leftUp.getX() << " "
        << rect.leftUp.getY() << " "
        << rect.rightDown.getX() << " "
        << rect.rightDown.getY();
    return os;
}

bool operator*(const CRectangle& rect1, const CRectangle& rect2)
{
    if (rect1.leftUp.getX() > rect2.rightDown.getX()
        || rect1.rightDown.getX() < rect2.leftUp.getX()
        || rect1.leftUp.getY() < rect2.rightDown.getY()
        || rect1.rightDown.getY() > rect2.leftUp.getY())
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    int t, x1, x2, y1, y2;
    cin >> t;
    while (t--)
    {
        // 矩形1的左上角、右下角
        cin >> x1 >> y1 >> x2 >> y2;
        CRectangle rect1(x1, y1, x2, y2);
        // 矩形2的左上角、右下角
        cin >> x1 >> y1 >> x2 >> y2;
        CRectangle rect2(x1, y1, x2, y2);
        // 输出矩形1的坐标及面积
        cout << "矩形1:" << rect1 << " " << (int)rect1 << endl;
        // 输出矩形2的坐标及面积
        cout << "矩形2:" << rect2 << " " << (int)rect2 << endl;
        if (rect1 == rect2)
        {
            cout << "矩形1和矩形2相等" << endl;
        }
        else if (rect2 > rect1)
        {
            cout << "矩形2包含矩形1" << endl;
        }
        else if (rect1 > rect2)
        {
            cout << "矩形1包含矩形2" << endl;
        }
        else if (rect1 * rect2)
        {
            cout << "矩形1和矩形2相交" << endl;
        }
        else
        {
            cout << "矩形1和矩形2不相交" << endl;
        }
        cout << endl;
    }
    return 0;
}