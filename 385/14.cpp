#include <iostream>
#include <cstring>

using namespace std;

int compare(const char *strA, const char *strB) {
    int a = 0, b = 0;
    int lengthA = strlen(strA);
    int lengthB = strlen(strB);
    if (lengthA < lengthB) {
        return -1;
    } else if (lengthA > lengthB) {
        return 1;
    }
    for (int i = 0; i < lengthA; i++) {
        if (strA[i] > strB[i]) {
            a++;
        } else if (strA[i] < strB[i]) {
            b++;
        }
    }
    if (a < b) {
        return -1;
    } else if (a > b) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int times;
    cin >> times;
    while (times--) {
        char strA[25];
        memset(strA, 0, sizeof(strA));
        char strB[25];
        memset(strB, 0, sizeof(strB));
        cin >> strA >> strB;
        cout << compare(strA, strB) << endl;
    }
}