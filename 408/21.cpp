#include <iostream>
#include <cstring>

using namespace std;

struct Paper {
    int id;
    char *first;
    char *second;
    char *third;
};

bool compareStr(const char *a, const char* b) {
    double lengthA = strlen(a), lengthB = strlen(b);
    double fimilar = 0;
    for (int i = 0; i < min(lengthA, lengthB); i++) {
        if (a[i] == b[i]) fimilar++;
    }
    return fimilar / min(lengthA, lengthB) >= 0.9;
}

int compare(const Paper *a, const Paper *b) {
    if (compareStr(a->first, b->first)) return 1;
    if (compareStr(a->second, b->second)) return 2;
    if (compareStr(a->third, b->third)) return 3;
    return 0;
}

int main() {
    int times;
    cin >> times;
    Paper* papers = new Paper[times];
    for (int i = 0; i < times; i++) {
        int id;
        char *first = new char[30];
        char *second = new char[30];
        char *third = new char[30];
        cin >> id >> first >> second >> third;
        papers[i] = Paper { id, first, second, third };
    }
    for (int i = 0; i < times; i++) {
        for (int j = i; j < times; j++) {
            if (i == j) continue;
            int result = compare(&papers[i], &papers[j]);
            if (result) {
                cout << papers[i].id << ' ' << papers[j].id << ' ' << result << endl;
            }
        }
    }
}