#include<iostream>

using namespace std;

// 定义Fraction类
class Fraction
{
private:
    int fz, fm;
    int commonDivisor(); // 计算最大公约数
    void contracted(); // 分数化简
public:
    Fraction(int = 0, int = 1);
    Fraction(Fraction&);
    Fraction operator+(Fraction);
    Fraction operator-(Fraction);
    Fraction operator*(Fraction);
    Fraction operator/(Fraction);
    void set(int = 0, int = 1);
    void disply();
};

// 构造函数
Fraction::Fraction(int fz, int fm)
{
    this->fz = fz;
    this->fm = fm;
    contracted();
}

// 复制构造函数
Fraction::Fraction(Fraction& f)
{
    fz = f.fz;
    fm = f.fm;
}

// 计算最大公约数
int Fraction::commonDivisor()
{
    return 1;
}

// 分数化简
void Fraction::contracted()
{
    return;
}

// 重载加法运算符
Fraction Fraction::operator+(Fraction f)
{
    Fraction temp;
    temp.fz = fz * f.fm + f.fz * fm;
    temp.fm = fm * f.fm;
    temp.contracted();
    return temp;
}

// 重载减法运算符
Fraction Fraction::operator-(Fraction f)
{
    Fraction temp;
    temp.fz = fz * f.fm - f.fz * fm;
    temp.fm = fm * f.fm;
    temp.contracted();
    return temp;
}

// 重载乘法运算符
Fraction Fraction::operator*(Fraction f)
{
    Fraction temp;
    temp.fz = fz * f.fz;
    temp.fm = fm * f.fm;
    temp.contracted();
    return temp;
}

// 重载除法运算符
Fraction Fraction::operator/(Fraction f)
{
    Fraction temp;
    temp.fz = fz * f.fm;
    temp.fm = fm * f.fz;
    temp.contracted();
    return temp;
}

// 设置分数
void Fraction::set(int fz, int fm)
{
    this->fz = fz;
    this->fm = fm;
    contracted();
}

// 显示分数
void Fraction::disply()
{
    cout << "fraction=" << fz << "/" << fm << endl;
}

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    Fraction f1(a, b), f2(c, d), f3;
    f3 = f1 + f2;
    f3.disply();
    f3 = f1 - f2;
    f3.disply();
    f3 = f1 * f2;
    f3.disply();
    f3 = f1 / f2;
    f3.disply();
    return 0;
}
