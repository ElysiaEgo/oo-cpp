#include<iostream>
#include<string>

using namespace std;

const int hmax = 26;
class Info { //联系人，用一个链表结点表示
	string name; //姓名
	int phoneNo; //电话
public:
	Info* next;  //指向下一个结点
	Info(string tn = "no name", int pno = 0)
	{
		name = tn;
		phoneNo = pno;
		next = nullptr;
	}
	void Print()
	{
		cout << name << "--" << phoneNo << endl;
	}
	//属性的get和set方法....自行定义
    void setName(string name)
    {
        this->name = name;
    }
    void setPhoneNo(int phoneNo)
    {
        this->phoneNo = phoneNo;
    }
    string getName()
    {
        return name;
    }
    int getPhoneNo()
    {
        return phoneNo;
    }
};

// 每个链表由n个链表结点组成，每个链表都有头结点，头结点不存放实际数据，纯粹作为一个索引。
// 所有链表的头结点组成一个数组，即数组的每个元素都是一个链表头结点，它的后面延伸着一个链表。
 
// 例如一个通讯录包含五个联系人，每个联系人都有姓名和电话，每个联系人都对应一个链表结点。
// Tom 8111
// Any 1222
// Ken 2333
// Kim 2444
// Tim 8222
// 我们先创建一个数组包含26个链表头结点，对应26个大写字母。因为有五个联系人，因此创建五个链表结点
// 因为上述联系人的姓名的首字母为A\K\T，因此把五个链表结点分别加入到三个头结点之后，形成三个链表。
// 其他字母的头结点因为无联系人，所以是空链表。构成组链表如下所示
// A--Any.1222
// K--Kim.2444--Ken.2333
// T--Tim.8222--Tom.8444
 

// 现在使用组链表来实现通讯录，通讯录是多个联系人的信息集合，每个联系人都包含姓名和电话属性。

// 每个联系人对应一个链表结点，姓名首字母相同的联系人放在同一个链表中。联系人的类定义基本写好，如下参考代码

// 通讯录的类界面如下代码，操作包括：
// 1、该类没有构造函数，使用输入函数Input实现数据的输入和通讯录的初始化
// 2、打印函数Print，输出整个通讯录，输出格式参考样本
// 3、插入新的联系人，重载运算符+=来实现，如果联系人姓名已经存在，则用新的电话覆盖旧电话
// 注意：插入采用头插法，即新结点直接插入头结点之后
// 4、查找联系人姓名，重载运算符()来实现，查找成功返回链表结点指针，失败返回NULL
// 5、合并两个通讯录，重载运算符+来实现，合并结果放在第一个通讯录中，即左操作数。
// 通讯录的合并实际上是两个相同首字母的链表合并。对于相同首字母的两个链表i和j合并过程如下：
// 1）第二个链表j从头开始，取出联系人信息，在第一个链表i中查找。
// 2）如果联系人已存在，则用第二个通讯录的电话覆盖第一个通讯录的电话
// 3）如果联系人不存在，则把联系人插入到第一个链表i中

class PhoneBook {//组链表方式实现通讯录
 //....自行增加一些操作
 //提示：把插入和查找先写成内部函数，再被运算符重载调用，会更方便
public:
	Info Table[hmax]; //链表头结点数组，对应26个大写字母
	//以下定义五个操作：输入Input、打印Print、插入、合并、查找
	//具体操作看前面说明
    void Input();
    void Print();
    void operator+=(Info& info);
    PhoneBook operator+(PhoneBook& phoneBook);
    Info* operator()(string name);
    ~PhoneBook();
    PhoneBook operator=(const PhoneBook& phoneBook);
};
//...PhoneBook类成员函数，类外实现，自行编写

void PhoneBook::Input()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string name;
        int phoneNo;
        cin >> name >> phoneNo;
        Info* info = new Info(name, phoneNo);
        int index = name[0] - 'A';
        Info* head = &Table[index];
        info->next = head->next;
        head->next = info;
    }
}

void PhoneBook::Print()
{
    for (int i = 0; i < hmax; i++)
    {
        Info* head = &Table[i];
        Info* info = head->next;
        if (info != nullptr) 
            cout << (char)(i + 'A') << "--";
        while (info != nullptr)
        {
            cout << info->getName() << "." << info->getPhoneNo();
            cout << "--";
            info = info->next;
        }
    }
}

void PhoneBook::operator+=(Info& info)
{
    int index = info.getName()[0] - 'A';
    Info* head = &Table[index];
    Info* p = head->next;
    while (p != nullptr)
    {
        if (p->getName() == info.getName())
        {
            p->setPhoneNo(info.getPhoneNo());
            return;
        }
        p = p->next;
    }
    info.next = head->next;
    head->next = &info;
}

PhoneBook PhoneBook::operator+(PhoneBook& phoneBook)
{
    PhoneBook result;
    for (int i = 0; i < hmax; i++)
    {
        Info* head = &Table[i];
        Info* info = head->next;
        while (info != nullptr)
        {
            result += *info;
            info = info->next;
        }
    }
    for (int i = 0; i < hmax; i++)
    {
        Info* head = &phoneBook.Table[i];
        Info* info = head->next;
        while (info != nullptr)
        {
            result += *info;
            info = info->next;
        }
    }
    *this = result;
    return result;
}

Info* PhoneBook::operator()(string name)
{
    int index = name[0] - 'A';
    Info* head = &Table[index];
    Info* info = head->next;
    while (info != nullptr)
    {
        if (info->getName() == name)
        {
            return info;
        }
        info = info->next;
    }
    return nullptr;
}

PhoneBook PhoneBook::operator=(const PhoneBook& phoneBook)
{
    for (int i = 0; i < hmax; i++)
    {
        Info* head = &Table[i];
        Info* info = head->next;
        while (info != nullptr)
        {
            Info* temp = info;
            info = info->next;
            delete temp;
        }
        head->next = nullptr;
    }
    for (int i = 0; i < hmax; i++)
    {
        const Info* head = &phoneBook.Table[i];
        Info* info = head->next;
        while (info != nullptr)
        {
            Info* temp = new Info(info->getName(), info->getPhoneNo());
            temp->next = Table[i].next;
            this->Table[i].next = temp;
            info = info->next;
        }
    }
    return *this;
}

PhoneBook::~PhoneBook() {}

//----主函数----
int main()
{
	string tname;
	int i, tno;
	Info* p;

	PhoneBook pb;
	pb.Input(); //接收输入数据，初始化第一个通讯录
	//两次姓名查找
	for (i = 0; i < 2; i++)
	{
		cin >> tname;
		p = pb(tname); //调用()运算符，实现查找
		if (p) p->Print(); //查找成功，输出联系人信息
		else cout << "查找失败" << endl; //查找失败，输出提示信息
	}
	//一次插入
	cin >> tname >> tno;
	Info temp(tname, tno);
	pb += temp; //调用+=运算符，实现插入新联系人
    cout <<"insert"<< endl;
	//通讯录合并
	PhoneBook pc;
	pc.Input(); //初始化第二个通讯录
	pb = pb + pc; //调用+运算符，实现合并

	pb.Print(); //输出所有操作后的通讯录

	return 0;
}