#include <iostream>
#include <utility>
using namespace std;

void reference(int &v)
{
    cout << "左值引用" << endl;
}
void reference(int &&v)
{
    cout << "右值引用" << endl;
}
template <typename T>
void pass(T &&v)
{
    cout << "普通传参: ";
    reference(v);
    cout << "std::move 传参:";
    reference(std::move(v));
    cout << "std::forward 传参:";
    reference(std::forward<T>(v));
    cout << "static_cast<T&&> 传参:";
    reference(static_cast<T &&>(v));
}

int main()
{
    cout << "传递右值:" << endl;
    pass(1);

    cout << "传递左值:" << endl;
    int v = 1;
    pass(v);

    return 0;
}