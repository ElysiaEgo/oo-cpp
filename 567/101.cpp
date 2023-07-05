#include<iostream>

using namespace std;

template <typename T>
class List
{
private:
    T* arr;
    int length;
public:
    List(T* data, int length)
    {
        arr = new T[100];
        this->length = length;
        for (int i = 0; i < length; i++)
            arr[i] = data[i];
        for (int i = length; i < 100; i++)
            arr[i] = -1;
    }
    List(const List& another)
    {
        length = another.length;
        for (int i = 0; i < length; i++)
            arr[i] = another.arr[i];
        for (int i = length; i < 100; i++)
            arr[i] = -1;
    }
    friend ostream& operator<<(ostream& out, const List& l)
    {
        for (int i = 0; i < l.length - 1; i++)
            out << l.arr[i] << ' ';
        out << l.arr[l.length - 1] << endl;
        return out;
    }
    void insert(int index, T data)
    {
        for (int i = length; i > index; i--)
            arr[i] = arr[i - 1];
        arr[index] = data;
        length++;
    }
    void remove(int index)
    {
        for (int i = index; i < length - 1; i++)
            arr[i] = arr[i + 1];
        length--;
    }
};

int main()
{
    while (true)
    {
        int length;
        cin >> length;
        if (!cin) break;
        auto idata = new int[length];
        for (int i = 0; i < length; i++)
            cin >> idata[i];
        auto ilist = List<int>(idata, length);
        int ind, num;
        cin >> ind >> num;
        ilist.insert(ind, num);
        cin >> ind;
        ilist.remove(ind);
        cout << ilist;
        cin >> length;
        auto ddata = new double[length];
        for (int i = 0; i < length; i++)
            cin >> ddata[i];
        auto dlist = List<double>(ddata, length);
        double dnum;
        cin >> ind >> dnum;
        dlist.insert(ind, dnum);
        cin >> ind;
        dlist.remove(ind);
        cout << dlist;
        delete[] idata;
    }
    return 0;
}