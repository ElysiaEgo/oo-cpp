#include<bits/stdc++.h>

using namespace std;

int main(){
    int times;
    cin >> times;
    while (times--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << 2 * (a * b + a * c + b * c) << endl;
    }
    return 0;
}
