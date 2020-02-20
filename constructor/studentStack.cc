#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Student
{
public:
    Student(const char * name, int id)
    : _name(new char[strlen(name) + 1]())
    , _id(id)
    {
        cout << "Student(const char * name, int id)" << endl;
        strcpy(_name, name);
    }
    
    void print() const
    {
        cout << "name :" << _name << endl
            << "id :" << _id << endl;
    }
private:
    void * operator new(size_t sz);
    void operator delete(void *ret);

public:
    ~Student()
    {
        delete [] _name;
        cout << "~Student()" << endl;
    }


private:
    char * _name;
    int _id;
};

void test()
{
    Student stu("Make", 111);
    stu.print();
}

int main()
{
    test();
    return 0;
}

