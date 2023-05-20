#include<iostream>
#include<string>

using namespace std;

class Animal
{ 
protected:
    string name, sound, kind;
public:
    Animal(string name, string sound, string kind)
    {
        this->name = name;
        this->sound = sound;
        this->kind = kind;
    }
    void speak()
    {
        cout << "Hello,I am " << this->name << ',' << this->sound << '.' << endl;
    }
};

class Tiger: public Animal
{
public:
    Tiger(string name): Animal(name, "AOOO", "Tiger") {}
};
class Dog: public Animal
{
public:
    Dog(string name): Animal(name, "WangWang", "Dog") {}
};
class Duck: public Animal
{
public:
    Duck(string name): Animal(name, "GAGA", "Duck") {}
};
class Pig: public Animal
{
public:
    Pig(string name): Animal(name, "HENGHENG", "Pig") {}
};

int main() {
    int times;
    cin >> times;
    Animal *animal = nullptr;
    while (times--)
    {
        string kind, name, age;
        cin >> kind >> name >> age;
        if (kind == "Tiger")
        {
            animal = new Tiger(name);
        }
        else if (kind == "Duck")
        {
            animal = new Duck(name);
        }
        else if (kind == "Dog")
        {
            animal = new Dog(name);
        }
        else if (kind == "Pig")
        {
            animal = new Pig(name);
        }
        else
        {
            cout << "There is no " << kind << " in our Zoo." << endl;
            continue;
        }
        if (animal != nullptr)
        {
            animal->speak();
            delete animal;
        }
    }
}