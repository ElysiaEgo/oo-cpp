#include<bits/stdc++.h>

using namespace std;

int main(){
    int times;
    cin >> times;
    while (times--) {
        int nums;
        cin >> nums;
        int weights[nums];
        int total_weight = 0;
        for (int i = 0; i < nums; i++) {
            int temp;
            cin >> temp;
            weights[i] = temp;
            total_weight += temp;
        }
        double aver_weight = total_weight / nums;
        int count = 0;
        for (int i = 0; i < nums; i++) {
            if (weights[i] > aver_weight) count++;
        }
        cout << count << endl;
    }
    return 0;
}
