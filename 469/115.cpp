#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class CVector
{
private:
    int *data;
    int n;
    static int sum;
public:
    CVector()
    {
        this->n = 5;
        this->data = new int[this->n];
        for (int i = 0; i < this->n; i++)
        {
            this->data[i] = i;
            this->sum += i;
        }
    }
    CVector(int n1, int *a)
    {
        this->n = n1;
        this->data = a;
        for (int i = 0; i < this->n; i++)
        {
            this->sum += data[i];
        }
    }
    void print()
    {
        for (int i = 0; i < this->n; i++)
        {
            cout << this->data[i];
            cout << ' ';
        }
    }
    static void printSum()
    {
        cout << sum << endl;
    }
    static void clearSum()
    {
        sum = 0;
    }
    float Average()
    {
        int total = 0;
        for (int i = 0; i < this->n; i++)
        {
            total += this->data[i];
        }
        return (float)total / (float)this->n;
    }
    friend CVector add(const CVector v1, const CVector v2);
    ~CVector()
    {
        delete[] this->data;
    }
};

CVector add(const CVector v1, const CVector v2)
{
    auto arr = new int[v1.n];
    for (int i = 0; i < v1.n; i++)
    {
        arr[i] = v1.data[i] + v2.data[i];
    }
    auto vec = CVector(v1.n, arr);
    return vec;
}

int CVector::sum = 0;

class CStudent
{
private:
    string name;
    CVector score;
public:
    CStudent(string name1, int n1, int *a): score(n1, a)
    {
        this->name = name1;
        //this->score = CVector(n1, a);
    }
    void print()
    {
        cout << this->name;
        cout << ' ';
        this->score.print();
        cout << fixed << setprecision(2) << this->score.Average() << endl;
    }
};

int main()
{
    while (true)
    {
        string name;
        cin >> name;
        if (!cin) break;
        int size;
        cin >> size;
        auto arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
        auto stu = new CStudent(name, size, arr);
        stu->print();
    }
    return 0;
}