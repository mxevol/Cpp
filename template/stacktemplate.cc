#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

template<class Type, int kSize = 10>
class Stack
{
public:
    Stack()
    : _top(-1)
    , _data(new Type[kSize]())
    {}

    bool empty() const;
    bool full() const;
    void push(const Type &t);
    void pop();
    Type top();

    ~Stack()
    {
        if(_data)
            delete [] _data;
    }

private:
    int _top;
    Type *_data;
};
template<class Type, int kSize>
bool Stack<Type, kSize>::empty() const
{
    return _top == -1;
}

template<class Type, int kSize>
bool Stack<Type, kSize>::full() const
{
    return _top == kSize - 1;
}

template<class Type, int kSize>
void Stack<Type, kSize>::push(const Type &t)
{
    if(!full()){
        _data[++_top] = t;
    }else{
        cout << "The Stack is full, cannot push anymore!" << endl;
    }
}

template<class Type, int kSize>
void Stack<Type, kSize>::pop()
{
    if(!empty()){
        --_top;
    }else{
        cout << "The Stack is empty, no any data!" << endl;
    }
}

template<class Type, int kSize>
Type Stack<Type, kSize>::top()
{
    return _data[_top];
}

int main()
{
    Stack<int> stack;
    cout << "Stack is empty?" << stack.empty() << endl;
    stack.push(1);
    cout << "Stack is empty?" << stack.empty() << endl;
    for(int idx = 2; idx != 12; idx++){
        stack.push(idx);
    }
    cout << "Stack is full ?" << stack.full() << endl;
    for(int idx = 0; idx != 10; idx++){
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
    return 0;
}

