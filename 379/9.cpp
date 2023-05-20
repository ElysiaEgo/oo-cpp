#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int times;
    cin >> times;
    int *nums;
    char *chars;
    double *dous;
    int total;
    char max;
    double min;
    while (times--) {
        char kind;
        int length;
        cin >> kind >> length;                
        switch (kind) {
            case 'I':
                nums = new int[length];
                for (int i = 0; i < length; i++) {
                    int tmp;
                    cin >> tmp;
                    *(nums + i) = tmp;
                }
                total = 0;
                for (int i = 0; i < length; i++) 
                    total += *(nums + i);
                cout << total / length << endl;
                delete[] nums;
                break;
            
            case 'C':
                chars = new char[length];
                for (int i = 0; i < length; i++) {
                    char tmp;
                    cin >> tmp;
                    *(chars + i) = tmp;
                }
                max = *chars;
                for (int i = 0; i < length; i++) 
                    if (*(chars + i) > max) max = *(chars + i);
                cout << max << endl;
                delete[] chars;
                break;

            case 'F':
                dous = new double[length];
                for (int i = 0; i < length; i++) {
                    double tmp;
                    cin >> tmp;
                    *(dous + i) = tmp;
                }
                min = *dous;
                for (int i = 0; i < length; i++) 
                    if (*(dous + i) < min) min = *(dous + i);
                cout << min << endl;
                delete[] dous;
                break;
        }
    }
}