#include <iostream>
using namespace std;

template <typename T0>
void printf1(T0 value)
{
    cout << value << endl;
}
template <typename T, typename... Ts>
void printf1(T value, Ts... args)
{
    cout << value << endl;
    printf1(args...);
}

template <typename T0, typename... T>
void printf2(T0 t0, T... t)
{
    cout << t0 << endl;
    if constexpr (sizeof...(t) > 0)
        printf2(t...);
}

template <typename T, typename... Ts>
auto printf3(T value, Ts... args)
{
    cout << value << endl;
    (void)initializer_list<T>{([&args]
                               { cout << args << endl; }(),
                               value)...};
}

int main()
{
    printf1("printf", 1, "works", "right");
    printf2("printf", 2, "works", "right");
    printf3("printf", 3, "works", "right");

    return 0;
}