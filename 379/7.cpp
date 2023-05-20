#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int times;
    cin >> times;
    while (times--) {
        int nums[3];
        for (int i = 0; i < 3; i++)
            cin >> nums[i];
        int* poi[3] = { &nums[0], &nums[1], &nums[2] };
        sort(poi, poi + 3, [] (int *a, int *b) -> bool {
            if (*a < *b) return false;
            return true;
        });
        cout << *poi[0] << ' ' << *poi[1] << ' '  << *poi[2] << endl;
    }
}