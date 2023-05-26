#include <iostream>
using namespace std;
class CVehicle
{
protected:
    int max_speed;
    int speed;
    int weight;
public:
    CVehicle(int m, int s, int w)
    {
        max_speed = m;
        speed = s;
        weight = w;
    }
    void display()
    {
        cout << "max_speed:" << max_speed << endl
            << "speed:" << speed << endl
            << "weight:" << weight << endl;
    }
};

class CBicycle : public CVehicle
{
protected:
    int height;
public:
    CBicycle(int m, int s, int w, int h) : CVehicle(m, s, w)
    {
        height = h;
    }
    void display()
    {
        CVehicle::display();
        cout << "height:" << height << endl;
    }
};

class CMotocar : public CVehicle
{
protected:
    int seat_num;
public:
    CMotocar(int m, int s, int w, int sn) : CVehicle(m, s, w)
    {
        seat_num = sn;
    }
    void display()
    {
        CVehicle::display();
        cout << "seat_num:" << seat_num << endl;
    }
};

class CMotocycle : public CBicycle, public CMotocar
{
public:
    CMotocycle(int m, int s, int w, int h, int sn) : CBicycle(m, s, w, h), CMotocar(m, s, w, sn)
    {
    }
    void display()
    {
        CBicycle::display();
        cout << "seat_num:" << seat_num << endl;
    }
};

int main()
{
    int max_speed, speed, weight, height, seat_num;
    cin >> max_speed >> speed >> weight >> height >> seat_num;
    CVehicle v(max_speed, speed, weight);
    cout << "Vehicle:" << endl;
    v.display();
    cout << endl;
    CBicycle b(max_speed, speed, weight, height);
    cout << "Bicycle:" << endl;
    b.display();
    cout << endl;
    CMotocar c(max_speed, speed, weight, seat_num);
    cout << "Motocar:" << endl;
    c.display();
    cout << endl;
    CMotocycle mc(max_speed, speed, weight, height, seat_num);
    cout << "Motocycle:" << endl;
    mc.display();
    return 0;
}
