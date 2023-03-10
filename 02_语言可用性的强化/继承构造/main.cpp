#include <iostream>
using namespace std;

class Base
{
public:
    int value1;
    int value2;
    Base()
    {
        value1 = 1;
    }
    Base(int value) : Base()
    {
        //委托 Base() 构造函数
        value2 = value;
    }
};

class Subclass : public Base
{
public:
    using Base::Base; // 继承构造
};

int main()
{
    Subclass s(3);
    cout << s.value1 << endl;
    cout << s.value2 << endl;
}