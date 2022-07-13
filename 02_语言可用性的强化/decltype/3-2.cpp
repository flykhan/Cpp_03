#include <iostream>
using namespace std;

int main()
{
    auto x = 1;
    auto y = 2;
    decltype(x + y) z;

    if (is_same<decltype(x), int>::value)
        cout << "type x == int" << endl;
    if (is_same<decltype(x), float>::value)
        cout << "type x == float" << endl;
    if (is_same<decltype(x), decltype(z)>::value)
        cout << "type z == type x" << endl;

    return 0;
}