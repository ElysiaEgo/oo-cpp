#include <iostream>
#include <algorithm>

using namespace std;

struct Date {
    int day;
    int mon;
    int yea;
};

int main() {
    int times;
    cin >> times;
    Date* birthdays = new Date[times];
    for (int i = 0; i < times; i++) {
        int y, m, d;
        cin >> y >> m >> d;
        birthdays[i] = Date { d, m, y };
    }
    sort(birthdays, birthdays + times, [](const Date &a, const Date &b) -> bool {
        if (a.yea != b.yea) return a.yea < b.yea;
        else if (a.mon != b.mon) return a.mon < b.mon;
        else return a.day < b.day;
    });
    cout << birthdays[1].yea << '-' << birthdays[1].mon << '-' << birthdays[1].day << endl;
}