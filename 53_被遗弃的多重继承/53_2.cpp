#include <iostream>
#include <string>

using namespace std;

class People
{
    string m_name;
    int m_age;
public:
    People(string name , int age)
    {
        m_name = name;
        m_age = age;
    }
    void print()
    {
        cout<<"Name = "<<m_name<<", "
            <<"Age = "<<m_age<<endl;
    }
};

class Teacher : virtual public People
{
public:
    Teacher(string name, int age) : People(name, age)
    {
    }
};

class Student : virtual public People
{
public:
    Student(string name, int age) : People(name, age)
    {
    }
};

class Doctor : public Teacher, public Student
{
public:
    Doctor(string name, int age) : Teacher(name, age), Student(name, age), People(name, age)
    {
    }
};

int main(int argc, const char *argv[])
{
    Doctor d("Quan", 27);
    cout<<"sizeof(string) = "<<sizeof(string)<<endl;
    cout<<"sizeof(People) = "<<sizeof(People)<<std::endl;
    cout<<"sizeof(Teacher) = "<<sizeof(Teacher)<<std::endl;
    cout<<"sizeof(Student) = "<<sizeof(Student)<<std::endl;
    cout<<"sizeof(Doctor) = "<<sizeof(d)<<std::endl;
    d.print();
    return 0;
}
