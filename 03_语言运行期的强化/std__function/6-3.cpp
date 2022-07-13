#include <functional>
#include <iostream>
using namespace std;

int foo(int para)
{
    return para;
}

int main()
{
    // std::funcion 包装了一个返回值为 int，参数为 int 的函数
    std::function<int(int)> func = foo;

    int important = 10;
    std::function<int(int)> func2 = [&](int value) -> int
    {
        return 1 + value + important;
    };

    cout << func(10) << endl;
    cout << func2(10) << endl;
    return 0;
}