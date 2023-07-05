#include<iostream>

using namespace std;

class Metal
{
private:
    int hard, weight, size;
public:
    Metal(int hard, int weight, int size)
    {
        this->hard = hard;
        this->weight = weight;
        this->size = size;
    }
    friend Metal operator+(const Metal& m1, const Metal& m2)
    {
        return Metal(m1.hard + m2.hard, m1.weight + m2.weight, m1.size + m2.size);
    }
    friend Metal operator*(const Metal& m1, int n)
    {
        return Metal(m1.hard, m1.weight, m1.size * n);
    }
    Metal operator++()
    {
        this->hard++;
        this->weight *= 1.1;
        this->size *= 1.1;
        return *this;
    }
    Metal operator--(int)
    {
        this->hard--;
        this->weight *= 0.9;
        this->size *= 0.9;
        return *this;
    }
    friend ostream& operator<<(ostream& out, const Metal& m)
    {
        out << "硬度" << m.hard << "--重量" << m.weight << "--体积" << m.size << endl;
        return out;
    }
    void print()
    {
        cout << *this;
    }
};

int main()
{
    int hard, weight, size;
    cin >> hard >> weight >> size;
    Metal m1(hard, weight, size);
    cin >> hard >> weight >> size;
    Metal m2(hard, weight, size);
    int n;
    cin >> n;
    Metal m3 = m1 + m2;
    Metal m4 = m1 * n;
    Metal m5 = ++m1;
    Metal m6 = m2--;
    m3.print();
    m4.print();
    m5.print();
    m6.print();
    return 0;
}