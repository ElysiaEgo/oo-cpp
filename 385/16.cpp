#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int times;
    cin >> times;
    while (times--) {
        int m, n;
        cin >> m >> n;
        int **matrix = new int*[m];
        for (int i = 0; i < m; i++) {
            matrix[i] = new int[n];
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        int min = matrix[0][0], max = matrix[0][0];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (min > matrix[i][j]) min = matrix[i][j];
                if (max < matrix[i][j]) max = matrix[i][j];
            }
        }
        cout << min << " " << max << endl;
        for (int i = 0; i < m; i++) {
            delete[] matrix[i];
        }
        delete matrix;
    }
}