#include <iostream>
using namespace std;

// 定义矩阵类
class CMatrix
{
private:
    int n, m; // n-行，m-列
    int** data; // 存储矩阵数据
public:
    CMatrix();
    CMatrix(const CMatrix& another);
    CMatrix(int n1, int m1);
    ~CMatrix();
    // 重载下标运算符
    int* operator[](int i);
    // 重载函数调用运算符
    int operator()(int i, int j);
    CMatrix operator=(const CMatrix& another);
};

CMatrix::CMatrix() = default;

CMatrix::CMatrix(const CMatrix& another)
{
    n = another.n;
    m = another.m;
    // 分配n行m列的二维数组空间
    data = new int* [n];
    for (int i = 0; i < n; i++)
    {
        data[i] = new int[m];
    }
    // 复制数据
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; ++j)
        {
            data[i][j] = another.data[i][j];
        }
    }
}

CMatrix::CMatrix(int n1, int m1)
{
    n = n1;
    m = m1;
    // 分配n行m列的二维数组空间
    data = new int* [n];
    for (int i = 0; i < n; i++)
    {
        data[i] = new int[m];
    }
}

CMatrix::~CMatrix()
{
    // 释放空间
    for (int i = 0; i < n; i++)
    {
        delete[] data[i];
    }
    delete[] data;
}

int* CMatrix::operator[](int i)
{
    return data[i];
}

int CMatrix::operator()(int i, int j)
{
    return data[i][j];
}

CMatrix CMatrix::operator=(const CMatrix& another)
{
    n = another.n;
    m = another.m;
    // 分配n行m列的二维数组空间
    data = new int* [n];
    for (int i = 0; i < n; i++)
    {
        data[i] = new int[m];
    }
    // 复制数据
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; ++j)
        {
            data[i][j] = another.data[i][j];
        }
    }
    return *this;
}

int main()
{
    int t, n, m, i, j;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        // 定义矩阵对象matrixA
        CMatrix matrixA(n, m);
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                // 输入第i行第j列的数据
                cin >> matrixA[i][j];
            }
        }
        // 输出matrixA中的数据
        cout << "matrixA:" << endl;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                cout << matrixA(i, j) << " ";
            }
            cout << endl;
        }
        // 定义矩阵对象matrixB
        CMatrix matrixB;
        matrixB = matrixA;
        // 输出marixB中的数据
        cout << "matrixB:" << endl;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                cout << matrixB[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}