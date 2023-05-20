#include<bits/stdc++.h>

using namespace std;

int main()
{
    int times;
    cin >> times;
    while (times--)
    {
        double rate;
        char result;
        cin >> rate;
        if (rate >= 85) result = 'A';
        else if (rate >= 75) result = 'B';
        else if (rate >= 65) result = 'C';
        else if (rate >= 60) result = 'D';
        else result = 'F';
        cout << result << endl;
    }
    return 0;
}
