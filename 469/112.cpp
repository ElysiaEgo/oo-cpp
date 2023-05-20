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
    ~CVector()
    {
        delete[] this->data;
    }
};

int main()
{
    auto vec1 = CVector();
    vec1.print();
    int size;
    cin >> size;
    auto arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    auto vec2 = CVector(size, arr);
    vec2.print();
    return 0;
}