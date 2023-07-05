#include<iostream>
#include<string>

using namespace std;

class Member
{
protected:
    string name;
    int id, point;
public:
    Member() = default;
    Member(string name, int id, int point)
    {
        this->name = name;
        this->id = id;
        this->point = point;
    }
    virtual void print()
    {
        cout << "普通会员" << id << "--" << name << "--" << point << endl;
    }
    virtual void add(int point)
    {
        this->point += point;
    }
    virtual int exchange(int point)
    {
        point -= point % 100;
        if (this->point < point)
            return -1;
        this->point -= point;
        return point / 100;
    }
};

class VIP: public Member
{
private:
    int plusDiscount;
    int exchangeDiscount;
public:
    VIP(string name, int id, int point, int plusDiscount, int exchangeDiscount): Member(name, id, point)
    {
        this->plusDiscount = plusDiscount;
        this->exchangeDiscount = exchangeDiscount;
    }
    virtual void print()
    {
        cout << "贵宾会员" << id << "--" << name << "--" << point << endl;
    }
    virtual void add(int point)
    {
        this->point += point * plusDiscount;
    }
    virtual int exchange(int point)
    {
        point -= point % exchangeDiscount;
        this->point -= point;
        return point / exchangeDiscount;
    }
};

int main ()
{
    Member* pm;
    int id, point, plusDiscount, exchangeDiscount;
    string name;
    cin >> id >> name >> point;
    pm = new Member(name, id, point);
    int a, b;
    cin >> a >> b;
    pm->add(a);
    pm->exchange(b);
    pm->print();
    cin >> id >> name >> point >> plusDiscount >> exchangeDiscount;
    pm = new VIP(name, id, point, plusDiscount, exchangeDiscount);
    cin >> a >> b;
    pm->add(a);
    pm->exchange(b);
    pm->print();
}