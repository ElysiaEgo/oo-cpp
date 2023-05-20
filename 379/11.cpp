#include<iostream>

using namespace std;

int main() {
    int times;
    cin >> times;
    while (times--) {
        int vec[2][3];
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++)
                cin >> vec[i][j];
        int vec_invert[3][2];
        int a = 0, b = 2;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                *(*(vec_invert + i) + j) = *(*(vec + a) + b);
                a++;
                if (a == 2) a = 0, b--;
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++)
                cout << *(*(vec_invert + i)+ j) << ' ';
            cout << endl;
        }
    }
}