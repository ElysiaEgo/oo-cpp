#include<iostream>
#include<cstring>

using namespace std;

enum PhoneType
{
    A = 'A', // goverment
    B = 'B', // enterprise
    C = 'C' // person
};

class PhoneNumber
{
    private:
    int number;
    PhoneType type;
    public:
    PhoneNumber(int number, PhoneType type)
    {
        this->number = number;
        this->type = type;
    }
    PhoneNumber(const PhoneNumber& another)
    {
        this->number = another.number;
        this->type = another.type;
    }

    int getNumber() const { return number; }
    void setNumber(int number_) { number = number_; }

    PhoneType getType() const { return type; }
    void setType(const PhoneType &type_) { type = type_; }
    
};

class Phone
{
    private:
    char * name;
    int status;
    PhoneNumber number;
    public:
    Phone(char * name, int status, int number, PhoneType type): number(number, type)
    {
        this->name = name;
        this->status = status;
        cout << this->number.getNumber() << " constructed." << endl;
    }
    Phone(const Phone& another): number(another.number)
    {
        this->name = new char[strlen(another.name)];
        strcpy(this->name, another.name);
        this->status = another.status;
    }
    void print()
    {
        cout << "Phone=" << this->number.getNumber()
        << "--Type=" << (char)this->number.getType()
        << "--State="<< (this->status == 0 ? "unuse" : "use")
        << "--Owner=" << this->name << endl;
    }
    ~Phone()
    {
        cout << this->number.getNumber() << " destructed." << endl;
        delete[] this->name;
    }

    char * getName() const { return name; }
    void setName(char * name_) { name = name_; }

    int getStatus() const { return status; }
    void setStatus(int status_) { status = status_; }

    PhoneNumber getNumber() const { return number; }
    void setNumber(const PhoneNumber &number_) { number = number_; }
};

int main() {
    auto phones = new Phone*[3];
    for (int i = 0; i < 3; i++)
    {
        int number, status;
        char type;
        char *name = new char[21];
        cin >> number >> type >> status >> name;
        phones[i] = new Phone(name, status, number, (PhoneType) type);
    }
    int times;
    cin >> times;
    while(times--)
    {
        int number;
        cin >> number;
        for (int i = 0; i < 3; i++)
        {
            if ((*phones[i]).getNumber().getNumber() == number)
            {
                (*phones[i]).print();
                break;
            }
            if (i == 2)
            {
                cout << "wrong number." << endl;
            }
        }
    }
    for (int i = 2; i >= 0; i--)
    {
        delete phones[i];
    }
    return 0;
}