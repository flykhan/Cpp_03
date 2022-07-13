#include <iostream>
using namespace std;

template <typename... T>
auto average(T... t)
{
    /*     auto sum = (t + ...);
        auto ave = sum / sizeof...(t);
        return ave; */

    return (t + ...) / sizeof...(t);
}

int main()
{
    cout << "average: " << average(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << endl;
}