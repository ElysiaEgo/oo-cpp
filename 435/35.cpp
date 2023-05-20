#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

class CStack
{
public:
    CStack();
    CStack(int s);
    int get(int index);
    void push(int n);
    int isEmpty();
    int isFull();
    int pop();
    ~CStack();
private:
    int* a;
    int size;
    int top = 0;
};

CStack::CStack()
{
    cout << "Constructor." << endl;
    this->a = new int[10];
    this->size = 10;
}
CStack::CStack(int s)
{
    cout << "Constructor." << endl;
    this->a = new int[s];
    this->size = s;
}
int CStack::get(int index)
{
    return a[index];
}
void CStack::push(int n)
{
    this->a[++top - 1] = n;
}
int CStack::isEmpty()
{
    return this->top == 0 ? 1 : 0;
}
int CStack::isFull()
{
    return this->top == size ? 1 : 0;
}
int CStack::pop()
{
    return this->a[--top];
}
CStack::~CStack()
{
    cout << "Destructor." << endl;
    delete[] a;
}

int main()
{
    int times;
    cin >> times;
    while (times--)
    {
        int num;
        cin >> num;
        auto stack = new CStack(num);
        while (num--) {
            int tmp;
            cin >> tmp;
            stack->push(tmp);
        }
        while (!stack->isEmpty())
        {
            cout << stack->pop();
            if (!stack->isEmpty()) cout << ' ';
        }
        cout << endl;
        delete stack;
    }
    return 0;
}