#include <iostream>
using namespace std;

template <typename T>
auto print_type_info(const T &t)
{
    if constexpr (is_integral<T>::value)
    {
        return t + 1;
    }
    else
    {
        return t + 0.001;
    }
}

int main()
{
    cout << print_type_info(5) << endl;
    cout << print_type_info(3.14) << endl;
}