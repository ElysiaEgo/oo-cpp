#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int times;
    cin >> times;
    while (times--) {
        int num;
        cin >> num;
        int *points = new int[num];
        int *mid = points + num / 2;
        for (int i = 0; i < num; i++) {
            cin >> points[i];
        }
        cout << *(--mid) << " ";
        mid++;
        cout << *(++mid) << endl;
        int query;
        cin >> query;
        cout << *(points + query - 1) << endl;
        delete[] points;
    }
}