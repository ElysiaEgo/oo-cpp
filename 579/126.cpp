#include<iostream>

using namespace std;

template<class T>
T max(T* arr, int length)
{
    T max = arr[0];
    for (int i = 1; i < length; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

template<class T>
class Cryption
{
private:
    T* message;
    T key;
    T* result;
    int length;
public:
    Cryption(T key, T* message, int length)
    {
        this->message = new T[length];
        this->length = length;
        for (int i = 0; i < length; i++)
            this->message[i] = message[i];
        this->key = key;
        result = new T[length];
    }
    void encrypt()
    {
        T maxVal = max(message, length);
        for (int i = 0; i < length; i++)
            result[i] = maxVal - message[i] + key;
    }
    void print()
	{
		int i;
		for (i = 0; i < length - 1; i++)
		{
			cout << result[i] << " ";
		}
		cout << result[i] << endl;
	}
};

//支持三种类型的主函数
int main()
{
	int i;
	int length; //长度
	int ik, itxt[100];
	double dk, dtxt[100];
	char ck, ctxt[100];
	//整数加密
	cin >> ik >> length;
	for (i = 0; i < length; i++)
	{
		cin >> itxt[i];
	}
	Cryption<int> ic(ik, itxt, length);
	ic.encrypt();
	ic.print();
	//浮点数加密
	cin >> dk >> length;
	for (i = 0; i < length; i++)
	{
		cin >> dtxt[i];
	}
	Cryption<double> dc(dk, dtxt, length);
	dc.encrypt();
	dc.print();
	//字符加密
	cin >> ck >> length;
	for (i = 0; i < length; i++)
	{
		cin >> ctxt[i];
	}
	Cryption<char> cc(ck, ctxt, length);
	cc.encrypt();
	cc.print();

	return 0;
}