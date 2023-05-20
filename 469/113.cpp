#include <iostream>

using namespace std;

class CVector
{
private:
    int *data;
    int n;
public:
    CVector()
    {
        this->n = 5;
        this->data = new int[this->n];
        for (int i = 0; i < this->n; i++)
        {
            this->data[i] = i;
        }
    }
    CVector(int n1, int *a)
    {
        this->n = n1;
        this->data = a;
    }
    void print()
    {
        for (int i = 0; i < this->n; i++)
        {
            cout << this->data[i];
            if (i == this->n - 1)
            {
                cout << endl;
            }
            else
            {
                cout << ' ';
            }
        }
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

int main()
{
    int times;
    cin >> times;
    while (times--) {
        int size;
        cin >> size;
        auto arr1 = new int[size];
        for (int i = 0; i < size; i++)
        {
            cin >> arr1[i];
        }
        auto vec1 = new CVector(size, arr1);
        vec1->print();
        auto arr2 = new int[size];
        for (int i = 0; i < size; i++)
        {
            cin >> arr2[i];
        }
        auto vec2 = new CVector(size, arr2);
        vec2->print();
        add(*vec1, *vec2).print();
    }
    return 0;
}