#include<bits/stdc++.h>

using namespace std;

int main(){
    int times;
    cin >> times;
    while (times--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a + b > c && b == c)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
