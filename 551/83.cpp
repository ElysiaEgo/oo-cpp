#include<iostream>

using namespace std;

class MyMatrix
{
private:
    int row, col;
    int** data;
public:
    MyMatrix(int, int);
    MyMatrix(const MyMatrix&);
    ~MyMatrix();
    MyMatrix operator*(MyMatrix&);
    friend istream& operator>>(istream& in, MyMatrix& matrix);
    MyMatrix& operator=(const MyMatrix&);
    void display();
    void set(int, int, int);
};

MyMatrix::MyMatrix(int row, int col)
{
    this->row = row;
    this->col = col;
    data = new int*[row];
    for (int i = 0; i < row; i++)
        data[i] = new int[col];
}

MyMatrix::MyMatrix(const MyMatrix& m)
{
    row = m.row;
    col = m.col;
    data = new int*[row];
    for (int i = 0; i < row; i++)
        data[i] = new int[col];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            data[i][j] = m.data[i][j];
}

MyMatrix::~MyMatrix()
{
    for (int i = 0; i < row; i++)
        delete[] data[i];
    delete[] data;
}

MyMatrix MyMatrix::operator*(MyMatrix& m)
{
    MyMatrix temp(row, m.col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < m.col; j++)
        {
            int sum = 0;
            for (int k = 0; k < col; k++)
                sum += data[i][k] * m.data[k][j];
            temp.data[i][j] = sum;
        }
    }
    return temp;
}

istream& operator>>(istream& in, MyMatrix& matrix)
{
    for (int i = 0; i < matrix.row; i++)
        for (int j = 0; j < matrix.col; j++)
            in >> matrix.data[i][j];
    return in;
}

MyMatrix& MyMatrix::operator=(const MyMatrix& m)
{
    if (this == &m)
        return *this;
    for (int i = 0; i < row; i++)
        delete[] data[i];
    delete[] data;
    row = m.row;
    col = m.col;
    data = new int*[row];
    for (int i = 0; i < row; i++)
        data[i] = new int[col];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            data[i][j] = m.data[i][j];
    return *this;
}

void MyMatrix::display()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col - 1; j++)
            cout << data[i][j] << " ";
        cout << data[i][col - 1] << endl;
    }
}

int main()
{
    int times;
    cin >> times;
    int n;
    cin >> n;
    MyMatrix m1(n, n);
    cin >> m1;
    times--;
    while (times--)
    {
        MyMatrix m2(n, n);
        cin >> m2;
        m1 = m1 * m2;
    }
    m1.display();
    return 0;
}