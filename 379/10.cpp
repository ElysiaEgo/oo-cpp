#include <iostream>

using namespace std;

int main() {
    int times;
    cin >> times;
    while (times--) {
        char str1[10], str2[10], str3[10];
        scanf("%s", str1);
        scanf("%s", str2);
        scanf("%s", str3);
        int a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;
        char *new_str = new char[b - a + d - c + f - e];
        int offset = 0;
        for (int i = a - 1; i < b; i++) {
            *(new_str + offset) = *(str1 + i);
            offset++;
        }
        for (int i = c - 1; i < d; i++) {
            *(new_str + offset) = *(str2 + i);
            offset++;
        }
        for (int i = e - 1; i < f; i++) {
            *(new_str + offset) = *(str3 + i);
            offset++;
        }
        cout << new_str << endl;
        delete[] new_str;
    }
}