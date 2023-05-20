#include <iostream>

using namespace std;

int main() {
    const char *pMonth[] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "Aguest",
        "September",
        "October",
        "November",
        "December"
    };
    int times;
    cin >> times;
    while (times--) {
        int month;
        cin >> month;
        if (month < 1 || month > 12)
            cout << "error" << endl;
        else
            cout << pMonth[month - 1] << endl;
    }
}