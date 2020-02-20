#include <string>
#include <iostream>
#include <limits>
using std::cout;
using std::endl;
using std::cin;
using std::string;

void printCinstatus() 
{
    cout << "cin's badbit :" << cin.bad() << endl
        << "cin's failbit :" << cin.fail() << endl
        << "cin's eofbit :" << cin.eof() << endl
        << "cin's goodbit :" << cin.good() << endl;
}

void test0()
{
    int number = -1;
    printCinstatus();

    while(cin >> number, !cin.eof()){
        cout << "number = " << number << endl;
        printCinstatus();
        if(!cin.good()){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            printCinstatus();
            break;
        }
    }
    cout << "input string" << endl;
    string str;
    cin >> str;
    cout << "str = " << str << endl;
}
int main()
{
    test0();
    return 0;
}

