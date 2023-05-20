#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

class Hotel
{
private:
    static int totalCustNum; // 顾客总人数
    static float totalEarning; // 旅店总收入
    static float rent; // 每个顾客的房租
    char *customerName; // 顾客姓名
    int customerId; // 顾客编号
public:
    // totalCustNum++，customerId按照totalCustNum生成
    Hotel(char* customer)
    {
        this->customerId = ++totalCustNum;
        totalEarning += rent;
        this->customerName = customer;
    }
    ~Hotel()
    {
        delete customerName;
    }
    void Display()
    {
        cout << this->customerName << ' '
            << 2015 << setfill('0') << setw(4) << this->customerId << ' '
            << totalCustNum << ' '
            << totalEarning << endl;
    }
    static void setRent(float re)
    {
        rent = re;
    }
};

int Hotel::totalCustNum; // 顾客总人数
float Hotel::totalEarning; // 旅店总收入
float Hotel::rent; // 每个顾客的房租

int main()
{
    float rent;
    cin >> rent;
    Hotel::setRent(rent);
    while (true)
    {
        char *cust = new char[20];
        cin >> cust;
        if (!strcmp(cust, "0")) break;
        auto hotel = Hotel(cust);
        hotel.Display();
    }
    return 0;
}