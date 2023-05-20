#include<iostream>
#include<cmath>

using namespace std;

class Group
{
public:
	virtual int add(int x, int y) = 0; // 输出加法的运算结果
	virtual int sub(int x, int y) = 0; // 输出减法的运算结果
};

class GroupA: public Group
{
public:
    int add(int x ,int y)
    {
        return x + y;
    }
    int sub(int x, int y)
    {
        return x - y;
    }
};
class GroupB: public Group
{
public:
    int add(int x ,int y)
    {
        return x + y;
    }
    int sub(int x, int y)
    {
        int al = (int)ceil(log10(x));
        int bl = (int)ceil(log10(y));
        auto a = new int[al];
        auto b = new int[bl];
        for (int i = 0; x > 0; i++, x /= 10)
        {
            a[i] = x % 10;
        }
        for (int i = 0; y > 0; i++, y /= 10)
        {
            b[i] = y % 10;
        }
        auto res = new int[max(al, bl)];
        for (int i = 0; i < max(al, bl); i++)
        {
            if (i < al)
            {
                if (i < bl)
                {
                    res[i] = a[i] < b[i] ? a[i] - b[i] + 10 : a[i] - b[i];
                }
                else
                {
                    res[i] = a[i];
                }
            }
            else
            {
                res[i] = b[i];
            }
        }
        auto result = 0;
        for (int i = 0; i < max(al, bl); i++)
        {
            result += res[i] * pow(10, i);
        }
        return result;
    }
};
class GroupC: public GroupB
{
public:
    int add(int x ,int y)
    {
        int al = (int)ceil(log10(x));
        int bl = (int)ceil(log10(y));
        auto a = new int[al];
        auto b = new int[bl];
        for (int i = 0; x > 0; i++, x /= 10)
        {
            a[i] = x % 10;
        }
        for (int i = 0; y > 0; i++, y /= 10)
        {
            b[i] = y % 10;
        }
        auto res = new int[max(al, bl)];
        for (int i = 0; i < max(al, bl); i++)
        {
            if (i < al)
            {
                if (i < bl)
                {
                    res[i] = (a[i] + b[i]) % 10;
                }
                else
                {
                    res[i] = a[i];
                }
            }
            else
            {
                res[i] = b[i];
            }
        }
        auto result = 0;
        for (int i = 0; i < max(al, bl); i++)
        {
            result += res[i] * pow(10, i);
        }
        return result;
    }
    using GroupB::sub;
};


int main() {
    int times;
    cin >> times;
    while (times--)
    {
        int type;
        cin >> type;
        Group* gro;
        int a, b;
        char op;
        switch (type)
        {
        case 1:
            gro = new GroupA();
            break;
        case 2:
            gro = new GroupB();
            break;
        case 3:
            gro = new GroupC();
            break;
        
        default:
            break;
        }
        cin >> a >> op >> b;
        if (op == '+')
        {
            cout << gro->add(a, b) << endl;;
        }
        else
        {
            cout << gro->sub(a, b) << endl;
        }
    }
}