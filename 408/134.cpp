#include <iostream>
#include <cstring>

using namespace std;

void find(int *num, int n, int &minIndex, int &maxIndex) {
    int max = num[0], min = num[0];
    minIndex = 0, maxIndex = 0;
    for (int i = 0; i < n; i++) {
        if (num[i] > max) maxIndex = i, max = num[i];
        else if (num[i] < min) minIndex = i, min = num[i];
    }
}

int main() {
    int times;
    cin >> times;
    while (times--) {
        int n;
        cin >> n;
        int *num = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        int minIndex, maxIndex;
        find(num, n, minIndex, maxIndex);
        cout << "min=" << num[minIndex] << " minindex=" << minIndex << endl;
        cout << "max=" << num[maxIndex] << " maxindex=" << maxIndex << endl;
        if (times != 0) cout << endl;
    }
}