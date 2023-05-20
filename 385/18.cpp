#include <iostream>
#include <cstring>

using namespace std;

char loopChar(char ch, int offset) {
    char newCh = ch + offset;
    if ((newCh >= 'a' && newCh <= 'z') || (newCh >= 'A' && newCh <= 'Z'))
        return newCh;
    if (newCh > 'z') return newCh - 'z' + 'a' - 1;
    if (newCh > 'Z') return newCh - 'Z' + 'A' - 1;
    if (newCh < 0) {
        return 'a' + offset - 'z' + ch - 1;
    }
    // should not be reached
    return ch;
}

int main() {
    int times;
    cin >> times;
    while (times--) {
        char message[20];
        memset(message, 0, sizeof(message));
        cin >> message;
        int keynum;
        cin >> keynum;
        int key[20];
        int keylength = 0;
        for (int i = 0; keynum > 0; i++) {
            *(key + i) = keynum % 10;
            keynum /= 10;
            keylength++;
        }
        char *cipher = new char[strlen(message)];
        memset(cipher, 0, sizeof(cipher));
        int offset = keylength - 1;
        for (int i = 0; i < strlen(message); i++) {
            char newChar = loopChar(*(message + i), *(key + offset));
            *(cipher + i) = newChar;
            offset--;
            if (offset < 0) offset = keylength - 1;
        }
        cout << cipher << endl;
        delete[] cipher;
    }
}