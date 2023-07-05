#include<iostream>

using namespace std;

template <typename T>
class Matrix
{
private:
    T** arr;
    int row, col;
public:
    Matrix(int row, int col)
    {
        this->row = row;
        this->col = col;
        arr = new T*[row];
        for (int i = 0; i < row; i++)
            arr[i] = new T[col];
    }
    Matrix(const Matrix& another)
    {
        row = another.row;
        col = another.col;
        arr = new T*[row];
        for (int i = 0; i < row; i++)
            arr[i] = new T[col];
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                arr[i][j] = another.arr[i][j];
    }
    ~Matrix()
    {
        for (int i = 0; i < row; i++)
            delete[] arr[i];
        delete[] arr;
    }
    friend ostream& operator<<(ostream& out, const Matrix& m)
    {
        for (int i = 0; i < m.row; i++)
        {
            for (int j = 0; j < m.col - 1; j++)
                out << m.arr[i][j] << ' ';
            out << m.arr[i][m.col - 1];
            out << endl;
        }
        return out;
    }
    friend istream& operator>>(istream& in, Matrix& m)
    {
        for (int i = 0; i < m.row; i++)
            for (int j = 0; j < m.col; j++)
                in >> m.arr[i][j];
        return in;
    }
    Matrix& operator=(const Matrix& another)
    {
        if (this == &another)
            return *this;
        if (arr != nullptr)
        {
            for (int i = 0; i < row; i++)
                if (arr[i] != nullptr)
                    delete[] arr[i];
            delete[] arr;
        }
        row = another.row;
        col = another.col;
        arr = new T*[row];
        for (int i = 0; i < row; i++)
            arr[i] = new T[col];
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                arr[i][j] = another.arr[i][j];
        return *this;
    }
    void transport()
    {
        Matrix temp(col, row);
        for (int i = 0; i < col; i++)
            for (int j = 0; j < row; j++)
                temp.arr[i][j] = arr[j][i];
        *this = temp;
    }
};

int main()
{
    Matrix<int>* imat;
    Matrix<double>* dmat;
    Matrix<char>* cmat;
    int times;
    cin >> times;
    while (times--) {
        char type;
        int row, col;
        cin >> type >> row >> col;
        switch(type)
        {
            case 'I':
                imat = new Matrix<int>(row, col);
                cin >> *imat;
                imat->transport();
                cout << *imat;
                delete imat;
                break;
            case 'D':
                dmat = new Matrix<double>(row, col);
                cin >> *dmat;
                dmat->transport();
                cout << *dmat;
                delete dmat;
                break;
            case 'C':
                cmat = new Matrix<char>(row, col);
                cin >> *cmat;
                cmat->transport();
                cout << *cmat;
                delete cmat;
                break;
        }

    }
    return 0;
}