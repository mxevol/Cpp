#include "Mylogger.h"
#include <sstream>
#include <iostream>
using namespace wd;
using std::cout;
using std::endl;

void test0()
{
    LogError("error messages");    
    LogInfo("info messages");    
    LogWarn("warn messages");    
    LogDebug("debug messages");    
}

void test1()
{
    int number = 1;
    const char* p = "hello,world";
    LogError("error messages");
    LogError("error messages %d , %s", number, p);
}
int main()
{
    test1();
    return 0;
}


