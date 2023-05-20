#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include <iomanip>
#include<cmath>
#include<cstring>
using namespace std;

class Date {
    string L;
    string num;
    string use;
    int year, month, day;
public:
    Date() {
        L = "0"; num = "0"; use = "0"; year = 0; month = 0; day = 0;
    }
    void set(string l,string n,string u,int y, int m, int d) {
        year = y; month = m; day = d;
        num = n; L = l; use = u;
    }
    void change1() {
        if (L == "A") L = "机构";
        if (L == "B")L = "企业";
        if (L == "C")L = "个人";
    }
    void change2() {
        if (use == "1")use = "在用";
        if (use == "2")use = "未用";
        if (use == "3")use = "停用";
    }
    void print1() {
        cout << "Construct a new phone " << num << endl;
        cout << "类型=" << L << "||号码=" << num << "||State=" << use << endl;
    }
    void print2() {
        cout << "Construct a copy of phone " << num << endl;
        cout << "类型=备份||号码=" << num << "X||State=" << use << endl;
    }
    void print3() {
        cout << "Stop the phone " << num << endl;
        cout << "类型=" << L << "||号码=" << num << "||State=停用||停机日期=" << year << '.' << month << '.' << day << endl << "----" << endl;
    }
    
    ~Date() {};
};
int main() {
    int time;
    cin >> time;
    int y, m, d;
    string num;
    string L;
    string use;
    Date* date = new Date[time];
    for (int i = 0; i < time;i++) {
        cin >> L >> num >> use >> y >> m >> d;
        date[i].set(L, num, use, y, m, d);
        date[i].change1();
        date[i].change2();
        date[i].print1();
        date[i].print2();
        date[i].print3();
    }
        return 0;
}