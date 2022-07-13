#include <iostream>
#include <string>
using namespace std;

// 字符串字面量自定义必须设置如下的参数列表
string operator"" _wow1(const char *wow1, size_t len)
{
    return string(wow1) + "woooooooooooow, amazing";
}

string operator"" _wow2(unsigned long long i)
{
    return to_string(i) + "woooooooooooow, amazing";
}

int main()
{
    auto str = "abc"_wow1;
    auto num = 1_wow2;
    cout << str << endl;
    cout << num << endl;
    return 0;
}