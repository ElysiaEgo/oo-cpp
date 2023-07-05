#include<iostream>
#include<map>
#include<string>

using namespace std;

template <typename T>
int findMax(T* arr, int length, int& res)
{
    map<T, int> m;
    int max = 0, maxi = 0;
    for (int i = 0; i < length; i++)
    {
        m[arr[i]]++;
        if (m[arr[i]] > max)
        {
            maxi = i;
            max = m[arr[i]];
        }
    }
    res = maxi;
    return max;
}

int main()
{
    int times;
    cin >> times;
    while (times--)
    {
        char type;
        cin >> type;
        int* iarr;
        char* carr;
        string* sarr;
        int resi, res;
        switch(type)
        {
            case 'I':
                int n;
                cin >> n;
                iarr = new int[n];
                for (int i = 0; i < n; i++)
                    cin >> iarr[i];
                res = findMax(iarr, n, resi);
                cout << iarr[resi] << ' ' << res << endl;
                delete[] iarr;
                break;
            
            case 'C':
                int c;
                cin >> c;
                carr = new char[c];
                for (int i = 0; i < c; i++)
                    cin >> carr[i];
                res = findMax(carr, c, resi);
                cout << carr[resi] << ' ' << res << endl;
                delete[] carr;
                break;
            
            case 'S':
                int s;
                cin >> s;
                sarr = new string[s];
                for (int i = 0; i < s; i++)
                    cin >> sarr[i];
                res = findMax(sarr, s, resi);
                cout << sarr[resi] << ' ' << res << endl;
                delete[] sarr;
                break;

            default:
                break;
        }
    }
    return 0;
}