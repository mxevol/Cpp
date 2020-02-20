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

    void * operator new(size_t sz)
    {
        cout << "void * operator new(size_t sz)" << endl;
        void * ret = malloc(sz);
        return ret;
    }

    void operator delete(void *ret)
    {
        cout << "void operator delete(void *ret)" << endl;
        free(ret);
    }


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

void test1()
{
    Student* pstu = new Student("lele", 0101);
    pstu->print();
    delete pstu;
}
int main()
{
    test1();
    return 0;
}

