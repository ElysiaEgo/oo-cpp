#include<iostream>
#include<string>

using namespace std;

template <typename T>
int findOne(T* arr, T& key, int length)
{
    for (int i = 0; i < length; i++)
        if (arr[i] == key)
            return i + 1;
    return 0;
}

int main()
{
    int times;
    cin >> times;
    string skey;
    while (times--)
    {
        string skey;
        char type;
        cin >> type;
        int *arr;
        double *darr;
        char *carr;
        string *sarr;
        switch (type)
        {
        case 'I':
            int n, ikey;
            cin >> n;
            arr = new int[n];
            for (int i = 0; i < n; i++)
                cin >> arr[i];
            cin >> ikey;
            cout << findOne(arr, ikey, n) << endl;
            delete[] arr;
            break;
        
        case 'D':
            int d;
            double dkey;
            cin >> d;
            darr = new double[d];
            for (int i = 0; i < d; i++)
                cin >> darr[i];
            cin >> dkey;
            cout << findOne(darr, dkey, d) << endl;
            delete[] darr;
            break;

        case 'C':
            int c;
            char ckey;
            cin >> c;
            carr = new char[c];
            for (int i = 0; i < c; i++)
                cin >> carr[i];
            cin >> ckey;
            cout << findOne(carr, ckey, c) << endl;
            delete[] carr;
            break;

        case 'S':
            int s;
            cin >> s;
            sarr = new string[s];
            for (int i = 0; i < s; i++)
                cin >> sarr[i];
            cin >> skey;
            cout << findOne(sarr, skey, s) << endl;
            delete[] sarr;
            break;
        
        default:
            break;
        }
    }
    return 0;
}