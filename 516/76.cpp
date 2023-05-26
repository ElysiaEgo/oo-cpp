#include <iostream>
#include <string>
using namespace std;
class TravelCard
{
protected:
    int cardNo;
    int travelPoints;
public:
    TravelCard(int no = 0, int points = 0) : cardNo(no), travelPoints(points) {}
    int getCardNo() { return cardNo; }
    int getTravelPoints() { return travelPoints; }
    void setTravelPoints(int points) { travelPoints = points; }
    void addTravelPoints(int points) { travelPoints += points; }
    virtual void show() = 0;
};
class CreditCard
{
protected:
    int cardNo;
    string name;
    int creditLimit;
    float bill;
    int creditPoints;
public:
    CreditCard(int no = 0, string n = "", int limit = 0, float b = 0, int points = 0) : cardNo(no), name(n), creditLimit(limit), bill(b), creditPoints(points) {}
    int getCardNo() { return cardNo; }
    string getName() { return name; }
    int getCreditLimit() { return creditLimit; }
    float getBill() { return bill; }
    int getCreditPoints() { return creditPoints; }
    void setBill(float b) { bill = b; }
    void addBill(float b) { bill += b; }
    void setCreditPoints(int points) { creditPoints = points; }
    void addCreditPoints(int points) { creditPoints += points; }
    virtual void show() = 0;
};
class TravelCreditCard : public TravelCard, public CreditCard
{
public:
    TravelCreditCard(int tno, int cno = 0, string n = "", int limit = 0, float b = 0, int points = 0) : TravelCard(tno, points), CreditCard(cno, n, limit, b, points) {}
    void show()
    {
        cout << TravelCard::cardNo << " " << travelPoints << endl;
        cout << CreditCard::cardNo << " " << name << " " << bill << " " << creditPoints << endl;
    }
    void order(float m)
    {
        if (m > creditLimit - bill)
            return;
        addBill(m);
        addTravelPoints(m);
        addCreditPoints(m);
    }
    void consume(float m)
    {
        if (m > creditLimit - bill)
            return;
        addBill(m);
        addCreditPoints(m);
    }
    void refund(float m)
    {
        addBill(-m);
        addCreditPoints(-m);
    }
    void exchange(float m)
    {
        if (m > creditPoints)
            return;
        addTravelPoints(m / 2);
        setCreditPoints(creditPoints - m);
    }
};

int main()
{
    int travelCardNo, creditCardNo, creditLimit, n;
    string name;
    float bill;
    int points;
    cin >> travelCardNo >> creditCardNo >> name >> creditLimit;
    TravelCreditCard tc(travelCardNo, creditCardNo, name, creditLimit);
    cin >> n;
    char op;
    float m;
    for (int i = 0; i < n; i++)
    {
        cin >> op >> m;
        switch (op)
        {
        case 'o':
            tc.order(m);
            break;
        case 'c':
            tc.consume(m);
            break;
        case 'q':
            tc.refund(m);
            break;
        case 't':
            tc.exchange(m);
            break;
        }
    }
    tc.show();
    return 0;
}
