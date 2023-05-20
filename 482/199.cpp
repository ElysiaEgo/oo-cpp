#include<iostream>
#include<cstring>

using namespace std;

enum RobotType
{
    N = 'N',
    A = 'A',
    D = 'D',
    H = 'H'
};

class Robot;

bool robotTransform(Robot *bot, RobotType newType);

class Robot
{
    private:
    char * name;
    int hp;
    int damage;
    int defend;
    RobotType type;
    int level;
    public:
    Robot(char * name, RobotType type, int level)
    {
        this->name = name;
        this->level = level;
        robotTransform(this, type);
    }
    Robot(const Robot& another)
    {
        this->name = new char[strlen(another.name)];
        strcpy(this->name, another.name);
        this->hp = another.hp;
        this->damage = another.damage;
        this->defend = another.defend;
        this->type = another.type;
        this->level = another.level;
    }
    void print()
    {
        cout << this->name << "--"
            << (char) this->type << "--"
            << this->level << "--"
            << this->hp << "--"
            << this->damage << "--"
            << this->defend << endl;
    }

    ~Robot()
    {
        delete this->name;
    }

    char * getName() const { return name; }
    void setName(char * name_) { name = name_; }

    int getHp() const { return hp; }
    void setHp(int hp_) { hp = hp_; }

    int getDamage() const { return damage; }
    void setDamage(int damage_) { damage = damage_; }

    int getDefend() const { return defend; }
    void setDefend(int defend_) { defend = defend_; }

    RobotType getType() const { return type; }
    void setType(const RobotType &type_) { type = type_; }

    int getLevel() const { return level; }
    void setLevel(int level_) { level = level_; }
};

bool robotTransform(Robot *bot, RobotType newType)
{
    if (bot->getType() == newType)
        return false;
    auto level = bot->getLevel();
    bot->setHp(level * 5);
    bot->setDamage(level * 5);
    bot->setDefend(level * 5);
    switch (newType)
    {
    case RobotType::N:
        bot->setType(RobotType::N);
        break;
    
    case RobotType::A:
        bot->setDamage(level * 10);
        bot->setType(RobotType::A);
        break;
    
    case RobotType::D:
        bot->setDefend(level * 10);
        bot->setType(RobotType::D);
        break;
    
    case RobotType::H:
        bot->setHp(level * 50);
        bot->setType(RobotType::H);
        break;
    
    default:
        break;
    }
    return true;
}

int main() {
    int times;
    cin >> times;
    int count = 0;
    while (times--)
    {
        auto buffer = new char[21];
        char type;
        int level;
        cin >> buffer >> type >> level;
        auto bot = new Robot(buffer, (RobotType) type, level);
        char newType;
        cin >> newType;
        if (robotTransform(bot, (RobotType) newType))
            count++;
        bot->print();
    }
    cout << "The number of robot transform is " << count << endl;
    return 0;
}