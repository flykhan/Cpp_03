#include <iostream>
#include <string>
using namespace std;

void reference(string &str)
{
    cout << "左值" << endl;
}
void reference(string &&str)
{
    cout << "右值" << endl;
}

int main()
{
    string lv1 = "string,"; // lv1 是一个左值
    // string &&r1 = lv1;      // 非法，右值引用不能引用左值
    string &&rv1 = std::move(lv1); // 合法，std::move可以将左值转移为右值
    cout << rv1 << endl;           // string,

    const string &lv2 = lv1 + lv1; // 合法，常量左值引用能够延长临时变量的生命周期
    // lv2 += "Test";                 // 非法，常量引用无法被修改
    cout << lv2 << endl; // string,string,

    string &&rv2 = lv1 + lv2; // 合法，右值引用延长临时对象生命周期
    rv2 += "Test";            // 合法，非常量引用能够修改临时变量
    cout << rv2 << endl;      // string,string,string,Test

    reference(rv2); // 输出左值

    return 0;
}