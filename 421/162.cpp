#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>

using namespace std;

//-----类定义------
class Person
{
    private:
    string name;
    double height;
    double weight;
    double waistline;

    public:
    string getName() const { return name; }
    void setName(const string &name_) { name = name_; }

    double getHeight() const { return height; }
    void setHeight(double height_) { height = height_; }

    double getWeight() const { return weight; }
    void setWeight(double weight_) { weight = weight_; }

    double getRound() const { return waistline; }
    void setRound(double round_) { waistline = round_; }

    double rate() {
        return (0.74 * waistline - weight * 0.082 - 34.89) / weight;
    }
    int bmi() {
        return round((weight / height / height));
    }
};
//----类实现------

//-----主函数-----
int main()
{
    int times;
    cin >> times;
    while (times--) {
        string name;
        double height;
        double weight;
        double round;
        cin >> name >> height >> weight >> round;
        auto per = new Person();
        per->setName(name);
        per->setHeight(height);
        per->setWeight(weight);
        per->setRound(round);
        cout << fixed << per->getName() << "的BMI指数为" << per->bmi() << "--体脂率为" << setprecision(2) << per->rate() << endl;
    }
    return 0;
}
