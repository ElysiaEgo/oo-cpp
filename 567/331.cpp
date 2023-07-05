#include<iostream>

using namespace std;

template <typename T>
bool verfiy(T* arr, int length)
{
    for (int i = 0; i < length - 1; i++)
        if (arr[i] > arr[i + 1])
            return false;
    return true;
}

int main()
{
    while (true)
    {
        char type;
        cin >> type;
        if (!cin) break;
        auto carr = new char[6];
        auto iarr = new int[6];
        auto farr = new double[6];
        switch (type)
        {
        case 'i':
            for (int i = 0; i < 6; i++)
                cin >> iarr[i];
            cout << (verfiy(iarr, 6) ? "Valid" : "Invalid") << endl;
            break;
        
        case 'c':
            for (int i = 0; i < 6; i++)
                cin >> carr[i];
            cout << (verfiy(carr, 6) ? "Valid" : "Invalid") << endl;
            break;
    
        case 'f':
            for (int i = 0; i < 6; i++)
                cin >> farr[i];
            cout << (verfiy(farr, 6) ? "Valid" : "Invalid") << endl;
            break;

        default:
            break;
        }
    }
    return 0;
}