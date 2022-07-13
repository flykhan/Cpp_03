#include <iostream>
using namespace std;

void reference(int &v)
{
    cout << "左值" << endl;
}
void reference(int &&v)
{
    cout << "右值" << endl;
}

template <typename T>
void pass(T &&v)
{
    cout << "普通传参:";
    reference(v); // 始终调用 reference(int&)
}

int main()
{
    cout << "传递右值:" << endl;
    pass(1); // 1 是右值，但输出是左值

    cout << "传递左值:" << endl;
    int l = 1;
    pass(l); // l 是左值，输出左值

    return 0;
}