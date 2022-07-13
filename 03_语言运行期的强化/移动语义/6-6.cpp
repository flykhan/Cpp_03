#include <iostream>
using namespace std;

class A
{
public:
    int *pointer;

public:
    A() : pointer(new int(1))
    {
        cout << "构造" << pointer << endl;
    }
    A(A &a) : pointer(new int(*a.pointer))
    {
        cout << "拷贝" << pointer << endl;
    }
    // 无意义的对象拷贝
    A(A &&a) : pointer(a.pointer)
    {
        a.pointer = nullptr; // 野指针
        cout << "移动" << pointer << endl;
    }
    ~A()
    {
        cout << "析构" << pointer << endl;
        delete pointer; // 销毁指针
    }
};

// 防止编译器优化
A return_rvalue(bool test)
{
    A a, b;
    if (test)
    {
        cout << "返回了a" << endl;
        return a; // 等价于static_cast<A&&>(a);
    }
    else
    {
        cout << "返回了b" << endl;
        return b; // 等价于static_cast<A&&>(b);
    }
}

int main()
{
    A obj = return_rvalue(false);
    cout << "obj:" << endl;
    cout << obj.pointer << endl;
    cout << *obj.pointer << endl;
    return 0;
}