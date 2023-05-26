#include <iostream>
#include <string>
using namespace std;
class CPeople
{
protected:
    string name;
    string sex;
    string age;
public:
    CPeople(string n, string s, string a)
    {
        name = n;
        sex = s;
        age = a;
    }
    virtual void print()
    {
        cout << "Name: " << name << endl
            << "Sex: " << sex << endl
            << "Age: " << age << endl;
    }
};

class CStudent : public CPeople
{
protected:
    string id;
    string score;
public:
    CStudent(string n, string sex, string a, string i, string s) : CPeople(n, sex, a)
    {
        id = i;
        score = s;
    }
    void print()
    {
        this->CPeople::print();
        cout << "No.: " << id << endl
            << "Score: " << score << endl;
    }
};

class CTeacher : public CPeople
{
protected:
    string position;
    string department;
public:
    CTeacher(string n, string sex, string a, string p, string d) : CPeople(n, sex, a)
    {
        position = p;
        department = d;
    }
    void print()
    {
        this->CPeople::print();
        cout << "Position: " << position << endl
            << "Department: " << department << endl;
    }
};

class CGradOnWork : public CStudent, public CTeacher
{
protected:
    string direction;
    string tutor;
public:
    CGradOnWork(string n, string sex, string a, string i, string s, string p, string department, string direction, string tutor): CStudent(n, sex, a, i, s), CTeacher(n, sex, a, p, department)
    {
        this->direction = direction;
        this->tutor = tutor;
    }
    void print()
    {
        this->CStudent::print();
        cout << "Position: " << position << endl
            << "Department: " << department << endl;
        cout << "Direction: " << direction << endl
            << "Tutor: " << tutor << endl;
    }
};

int main() {
    string name, sex, age, id, score, position, department, direction, tutor;
    cin >> name >> sex >> age >> id >> score >> position >> department >> direction >> tutor;
    CPeople peo(name, sex, age);
    cout << "People:" << endl;
    peo.print();
    cout << endl;
    CStudent stu(name, sex, age, id, score);
    cout << "Student:" << endl;
    stu.print();
    cout << endl;
    CTeacher tea(name, sex, age, position, department);
    cout << "Teacher:" << endl;
    tea.print();
    cout << endl;
    CGradOnWork gow(name, sex, age, id, score, position, department, direction, tutor);
    cout << "GradOnWork:" << endl;
    gow.print();
}
