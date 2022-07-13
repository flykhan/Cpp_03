#include <iostream>
using namespace std;
template <typename T, typename U>
auto add2(T x, U y) -> decltype(x + y)
{
    return x + y;
}

template <typename T, typename U>
auto add3(T x, U y)
{
    return x + y;
}

int main()
{
    // after c++11
    auto w = add2<int, double>(1, 2.0);
    if (is_same<decltype(w), double>::value)
    {
        cout << "w is double: ";
    }
    cout << w << endl;

    // after c++14
    auto q = add3<double, int>(1.0, 2);
    if (is_same<decltype(q), double>::value)
    {
        cout << "q is double: ";
    }
    cout << q << endl;
}