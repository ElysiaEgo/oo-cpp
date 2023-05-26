#include<iostream>
#include<cmath>

using namespace std;

class Student{
protected:
  string name; //学生姓名
  int type; //学生类别:1表示本科生，2表示研究生
  int courses[3]; //3门课的成绩
  string courseGrade; //成绩等级
public:
  Student(string n,string t,int a1,int a2,int a3);//构造方法
  virtual void calculateGrade()=0;//计算成绩等级
  void print();//输出信息
};

Student::Student(string n,string t,int a1,int a2,int a3){
  name=n;
  if (t=="1") type=1;
  else type=2;
  courses[0]=a1;
  courses[1]=a2;
  courses[2]=a3;
}

void Student::print() {
  cout<<name<<","<<(type == 1 ? "本科生" : "研究生")<<","<<courseGrade<<endl;
}

class Undergraduate: public Student
{
    public:
    using Student::Student;
    void calculateGrade()
    {
        int sum = 0;
        for (int i = 0; i < 3; i++)
        {
            sum += courses[i];
        }
        int average = sum / 3;
        courseGrade = "不及格";
        if (average >= 80)
        {
            courseGrade = "优秀";
        }
        else if (average >= 70)
        {
            courseGrade = "良好";
        }
        else if (average >= 60)
        {
            courseGrade = "一般";
        }
        else if (average >= 50)
        {
            courseGrade = "及格";
        }
    }
};

class Postgraduate: public Student
{
    public:
    using Student::Student;
    void calculateGrade()
    {
        int sum = 0;
        for (int i = 0; i < 3; i++)
        {
            sum += courses[i];
        }
        int average = sum / 3;
        courseGrade = "不及格";
        if (average >= 90)
        {
            courseGrade = "优秀";
        }
        else if (average >= 80)
        {
            courseGrade = "良好";
        }
        else if (average >= 70)
        {
            courseGrade = "一般";
        }
        else if (average >= 60)
        {
            courseGrade = "及格";
        }
    }
};

int main() {
    int times;
    cin >> times;
    while (times--)
    {
        Student* stu;
        string name, type;
        int a, b, c;
        cin >> name >> type >> a >> b >> c;
        if (type == "1")
        {
            stu = new Undergraduate(name, type, a, b, c);
        }
        else
        {
            stu = new Postgraduate(name, type, a, b, c);
        }
        stu->calculateGrade();
        stu->print();
    }
}