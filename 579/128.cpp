#include<iostream>
#include<cstring>

using namespace std;

class CN; //提前声明
class EN; //提前声明

// 抽象类
class Weight
{
protected:
	char kind[20]; //计重类型
	int gram; // 克
public:
	Weight(const char tk[] = "no name", int tg = 0)
	{
		strcpy(kind, tk);
		gram = tg;
	}
	virtual void print(ostream& out) = 0; // 输出不同类型的计重信息
};

// 中国计重
class CN : public Weight
{
	// ....类定义自行编写
private:
    int jin, liang, qian;
public:
    CN(int jin, int liang, int qian, int gram, const char tk[]): Weight(tk, gram)
    {
        this->jin = jin;
        this->liang = liang;
        this->qian = qian;
    }
    void Convert(int tw)
    {
        jin = tw / 500;
        liang = tw % 500 / 50;
        qian = tw % 500 % 50 / 5;
        gram = tw % 500 % 50 % 5;
    }
    void print(ostream& out)
    {
        out << kind << ':' << jin << "斤" << liang << "两" << qian << "钱" << gram << "克" << endl;
    }
    friend ostream& operator<<(ostream& out, CN& cn)
    {
        cn.print(out);
        return out;
    }
};

// 英国计重
class EN : public Weight
{
	// ....类定义自行编写
private:
    int pound, ounce, drachm;
public:
    EN(int pound, int ounce, int drachm, int gram, const char tk[]): Weight(tk, gram)
    {
        this->pound = pound;
        this->ounce = ounce;
        this->drachm = drachm;
    }
    void Convert(int tw)
    {
        pound = tw / 512;
        ounce = tw % 512 / 32;
        drachm = tw % 512 % 32 / 2;
        gram = tw % 512 % 32 % 2;
    }
    void print(ostream& out)
    {
        out << kind << ':' << pound << "磅" << ounce << "盎司" << drachm << "打兰" << gram << "克" << endl;
    }
    friend ostream& operator<<(ostream& out, EN& en)
    {
        en.print(out);
        return out;
    }
    // overload type conversion
    operator CN()
    {
        CN cn(0, 0, 0, 0, "中国计重");
        cn.Convert(pound * 512 + ounce * 32 + drachm * 2 + gram);
        return cn;
    }
};

// 以全局函数方式重载输出运算符，代码3-5行....自行编写
// 重载函数包含两个参数：ostream流对象、Weight类对象，参数可以是对象或对象引用
// 重载函数必须调用参数Weight对象的print方法

// 主函数
int main()
{
	int tw;
	// 创建一个中国计重类对象cn
	// 构造参数对应斤、两、钱、克、类型，其中克和类型是对应基类属性gram和kind
	CN cn(0, 0, 0, 0, "中国计重");
	cin >> tw;
	cn.Convert(tw); // 把输入的克数转成中国计重
	cout << cn;

	// 创建英国计重类对象en
	// 构造参数对应磅、盎司、打兰、克、类型，其中克和类型是对应基类属性gram和kind
	EN en(0, 0, 0, 0, "英国计重");
	cin >> tw;
	en.Convert(tw); // 把输入的克数转成英国计重
	cout << en;
	cn = en; // 把英国计重转成中国计重
	cout << cn;
	return 0;
}