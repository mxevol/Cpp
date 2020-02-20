#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::istringstream;
using std::ostringstream;
using std::stringstream;

void test0()
{
    int val1 = 1;
    int val2 = 2;
    stringstream ss;
    ss << "val1= " << val1 << " ,val2= " << val2;
    cout << ss.str() << endl;
    string str;
    int number;
    while(!ss.eof()){
        ss >> str >> number;
        cout << str << "--->" << number << endl;
    }
}

string inttostr(int number)
{
    ostringstream os;
    os << number;
    return os.str();
}

void readConfiguration(const string & filename)
{
    ifstream ifs(filename);
    if(!ifs.good()){
        cout << "ifstram open " << filename << "error " << endl;
        return;
    }
    string line;
    while(getline(ifs, line)){
        istringstream is(line);
        string key, value;
        is >> key >> value;
        cout << key << "----> " << value << endl;
    }
    ifs.close();
}

void test1()
{
    int number = 1024;
    cout << inttostr(number) << endl;
    readConfiguration("my.conf");
}
int main()
{
    test1();
    return 0;
}

