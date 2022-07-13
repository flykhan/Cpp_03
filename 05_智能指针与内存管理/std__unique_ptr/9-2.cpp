#include <iostream>
#include <memory>
using namespace std;

// struct 抽象类
struct Foo
{
    Foo() { cout << "Foo::Foo" << endl; }
    ~Foo() { cout << "Foo::~Foo" << endl; }
    void foo() { cout << "Foo::foo" << endl; }
};

void f(const Foo &)
{
    cout << "f(const Foo&)" << endl;
}

int main()
{
    // 新创建，调用构造函数，输出 Foo::Foo
    unique_ptr<Foo> pointer1(make_unique<Foo>());
    // pointer1 不空，输出 Foo::foo
    if (pointer1)
        pointer1->foo();
    {
        unique_ptr<Foo> pointer2(move(pointer1));
        // pointer2 不空，输出 f(const Foo&)
        f(*pointer2);
        // pointer2 不空，输出 Foo::foo
        if (pointer2)
            pointer2->foo();
        // pointer1 为空，无输出
        if (pointer1)
            pointer1->foo();
        pointer1 = move(pointer2);
        // pointer2 为空，无输出
        if (pointer2)
            pointer2->foo();
        cout << "pointer2 被销毁" << endl; // 即将离开pointer2作用域，pointer2 被销毁
    }
    // pointer1 不空，输出 Foo::foo
    if(pointer1) pointer1->foo();
    // if(pointer2) pointer2->foo(); // 错误，pointer2 已经离开定义它的作用域
    // Foo 的实例会在离开作用域时被销毁，调用析构函数，输出 Foo::~Foo
}