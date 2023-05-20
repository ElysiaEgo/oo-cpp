#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int times;
    cin >> times;
    double rates[4] = {6.2619, 6.6744, 0.0516, 0.8065};
    while (times--) {
        char kind;
        cin >> kind;
        int rate_offset = 0;
        switch (kind)
        {
        case 'D':
            rate_offset = 0;
            break;
        case 'E':
            rate_offset = 1;
            break;
        case 'Y':
            rate_offset = 2;
            break;
        case 'H':
            rate_offset = 3;
            break;
        
        default:
            break;
        }
        double value;
        cin >> value;
        double a = value * *(rates + rate_offset);
        cout << fixed << setprecision(4) << a <<endl;
    }
}