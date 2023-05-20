#include<iostream>
#include<string>

using namespace std;

class Student {
    public:
        string name;
        string id;
        string gender;
        string org;
        string phone;
};

int main() {
    int times;
    cin >> times;
    auto stus = new Student[times];
    for (int i = 0; i < times; i++) {
        cin >> stus[i].name >> stus[i].id >> stus[i].gender >> stus[i].org >> stus[i].phone;
    }
    for (int i = 0; i < times; i++) {
        cout << stus[i].name << endl;
    }
}
