#include <iostream>
using namespace std;

using foo = void(int); // 定义函数类型，using 的使用见上一节中的别名语法
void functional(foo f)
{
    // 定义在参数列表中的函数类型 foo 被视为退化后的函数指针类型 foo*
    f(1); // 通过函数指针调用函数
}

int main()
{
    auto f = [](int value)
    {
        cout << value << endl;
    };
    functional(f); // 传递闭包对象，隐式转换为 foo* 类型的函数指针值
    f(1);          // lambda 表达式调用
    return 0;
}