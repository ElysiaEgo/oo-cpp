#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class CMatrix;

class CVector
{
private:
    int *data;
    int n;
    friend class CMatrix;
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
    CVector(int n1)
    {
        this->n = n1;
        this->data = new int[this->n];
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
    float Average()
    {
        int total = 0;
        for (int i = 0; i < this->n; i++)
        {
            total += this->data[i];
        }
        return (float)total / (float)this->n;
    }
    ~CVector()
    {
        // delete[] this->data;
    }
};

class CMatrix
{
private:
    int n;
    CVector *rows;
public:
    CMatrix(int n, int **data)
    {
        this->n = n;
        this->rows = new CVector[n];
        for (int i = 0; i < this->n; i++)
        {
            this->rows[i] = CVector(n, data[i]);
        }
    }
    CVector multi(const CVector &v1)
    {
        auto vec = CVector(v1.n);
        for (int i = 0; i < this->n; i++)
        {
            int res = 0;
            for (int j = 0; j < this->rows[i].n; j++)
            {
                res += this->rows[i].data[j] * v1.data[j];
            }
            vec.data[i] = res;
        }
        return vec;
    }
    bool canMulti(const CVector &v1)
    {
        return v1.n == this->n;
    }
    ~CMatrix()
    {
        delete[] rows;
    }
};

int main()
{
    int times;
    cin >> times;
    while (times--)
    {
        int n;
        int** data;
        cin >> n;
        data = new int*[n];
        for (int i = 0; i < n; i++)
        {
            data[i] = new int[n];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> data[i][j];
            }

        }
        auto matrix = CMatrix(n, data);
        int size;
        cin >> size;
        auto arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
        CVector vec(size, arr);
        if (matrix.canMulti(vec))
        {
            matrix.multi(vec).print();
        }
        else
        {
            cout << "error" << endl;
        }
    }
    return 0;
}