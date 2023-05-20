#include<iostream>
#include<string>

using namespace std;

class Vehicle
{ 
protected:
    string no;
    int pass, weight;
public:
    virtual void display() = 0;
};

class Car: public Vehicle
{
public:
    Car(string no, int pass, int weight): Vehicle()
    {
        this->no = no;
        this->pass = pass, this->weight = weight;
    }
    void display()
    {
        cout << this->no << ' ' << this->pass * 8 + this->weight * 2 << endl;
    }
};
class Truck: public Vehicle
{
public:
    Truck(string no, int weight): Vehicle()
    {
        this->no = no;
        this->weight = weight;
    }
    void display()
    {
        cout << this->no << ' ' << this->weight * 5 << endl;
    }
};
class Bus: public Vehicle
{
public:
    Bus(string no, int pass): Vehicle()
    {
        this->no = no;
        this->pass = pass;
    }
    void display()
    {
        cout << this->no << ' ' << this->pass * 30 << endl;
    }
};

int main() {
    int times;
    cin >> times;
    while (times--)
    {
        int type;
        cin >> type;
        string no;
        cin >> no;
        Vehicle* pv;
        int p, w;
        if (type == 1)
        {
            cin >> p >> w;
            pv = new Car(no, p, w);
        }
        else if (type == 2)
        {
            cin >> w;
            pv = new Truck(no, w);
        }
        else
        {
            cin >> p;
            pv =  new Bus(no, p);
        }
        pv->display();
    }
}