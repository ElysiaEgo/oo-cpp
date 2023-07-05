#include<iostream>
#include<string>

using namespace std;

//家具
class Furniture
{
protected:
    int id, watt;
public:
    Furniture() = default;
    Furniture(int id, int watt)
    {
        this->id = id;
        this->watt = watt;
    }
};

// 电风扇
class Fan: public Furniture
{
protected:
    int direction, speed;
public:
    Fan(int id, int watt, int direction, int speed): Furniture(id, watt)
    {
        this->direction = direction;
        this->speed = speed;
    }
    void setDirection(int direction)
    {
        this->direction = direction;
    }
    void setSpeed(int speed)
    {
        this->speed = speed;
    }
};

//加湿器
class Humidifier: public Furniture
{
protected:
    int capacity;
    int maxCapacity;
public:
    Humidifier(int id, int watt, int capacity, int maxCapacity): Furniture(id, watt)
    {
        this->capacity = capacity;
        this->maxCapacity = maxCapacity;
    }
    int warn()
    {
        if (capacity > maxCapacity / 2)
            return 1;
        else if (capacity > maxCapacity / 10)
            return 2;
        else
            return 3;
    }
};

// 加湿风扇
class FanHumidifier: public Fan, public Humidifier
{
protected:
    int prop;
public:
    FanHumidifier(int id, int watt, int direction, int speed, int capacity, int maxCapacity): Fan(id, watt, direction, speed), Humidifier(id, watt, capacity, maxCapacity)
    {
    }
    virtual void print()
    {
        cout << "加湿风扇--档位" << prop << endl
            << "编号" << Fan::id << "--功率" << Fan::watt << "W" << endl    
            << (direction == 0 ? "定向吹风" : "旋转吹风" )<< "--风力" << speed << "级" << endl
            << "实际水容量" << capacity << "升--" << (warn() == 1 ? "水量正常" : (warn() == 2 ? "水量偏低" : "水量不足")) << endl;
    }
    void control(int prop)
    {
        this->prop = prop;
        if (prop == 1)
        {
            setDirection(0);
            setSpeed(1);
        }
        else if (prop == 2)
        {
            setDirection(1);
            setSpeed(2);
        }
        else if (prop == 3)
        {
            setDirection(1);
            setSpeed(3);
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int id, watt, direction, speed, capacity, maxCapacity, prop;
        cin >> id >> watt >> direction >> speed >> capacity >> maxCapacity >> prop;
        cin >> prop;
        FanHumidifier fanHumidifier(id, watt, direction, speed, capacity, maxCapacity);
        fanHumidifier.control(prop);
        fanHumidifier.print();
    }
    return 0;
}