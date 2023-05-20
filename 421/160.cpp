#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

//-----类定义------
class Cat
{
    private:
    string name;
    int weight;
    public:
    string getName();
    int getWeight();
    void setName(string name);
    void setWeight(int weight);
};
//----类实现------
string Cat::getName()
{
    return this->name;
};
int Cat::getWeight()
{
    return this->weight;
};
void Cat::setName(string name) {
    this->name = name;
}
void Cat::setWeight(int weight) {
    this->weight = weight;
}

//-----主函数-----
int main()
{
    int num;
    cin >> num;
    auto cats = new Cat[num];
    for (int i = 0; i < num; i++) {
        string tempName;
        int tempWeight;
        cin >> tempName >> tempWeight;
        cats[i].setName(tempName);
        cats[i].setWeight(tempWeight);
    }
    sort(cats, cats + num, [](Cat a, Cat b) -> bool {
        return a.getWeight() < b.getWeight();
    });
    for (int i = 0; i < num; i++) {
        if (i != 0) cout << " ";
        cout << cats[i].getName();
    }
    cout << endl;
    return 0;
}
