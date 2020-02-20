#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::cin;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;

void printCinstatus(ifstream & ifs) 
{
    cout << "ifs's badbit :" << ifs.bad() << endl
        << "ifs's failbit :" << ifs.fail() << endl
        << "ifs's eofbit :" << ifs.eof() << endl
        << "ifs's goodbit :" << ifs.good() << endl;
}
vector<string> file;
void test0()
{
   ifstream ifs("hello.txt");
   if(!ifs.good()){
       cout << ">> ifstream open file error!" << endl;
       return;
   }
   string line;
   while(getline(ifs, line)){
       cout << line << endl;
       file.push_back(line);
   }
   cout << "ifs.tellg = " << ifs.tellg() << endl;
   printCinstatus(ifs);
   ifs.close();
}

void test1()
{
    ofstream ofs("text.txt");
    if(!ofs.good()){
        cout << ">> oftream open file error!" << endl;
    }
    for(auto & line : file){
        ofs << line << endl;
    }
   cout << "ofs.tellp = " << ofs.tellp() << endl;
    ofs.close();
}
void test2()
{
    fstream fs("fs.txt");
    if(!fs.good()){
        cout << " >> fstream open file error!" << endl;
        return;
    }
    int number;
    cout << "pls input 10 integer number " << endl;
    for(int idx = 0; idx != 10; idx++){
        cin >> number;
        fs << number << " ";
    }
    cout << "fs's pos = " << fs.tellg() << endl;
    fs.seekg(0);
    for(int idx = 0; idx != 10; idx++){
        fs >> number;
        cout << number << " ";
    }
    cout << endl;
    fs.close();

}

void test3()
{
    string filename = "hello.txt";
    ifstream ifs(filename, std::ios::ate);
    if(!ifs.good()){
        cout << "ifs's open " << filename << " error! " << endl;
        return ;
    }
    int length = ifs.tellg();
    cout << "length = " << length << endl;
    char * buf = new char[length + 1]();
    ifs.seekg(std::ios::beg);
    ifs.read(buf, length);
    string content(buf);
    cout << endl;
    cout << content << endl;
    delete [] buf;
    ifs.close();

}
int main()
{
    //test0();
    //test1();
    //test2();
    test3();
    return 0;
}

