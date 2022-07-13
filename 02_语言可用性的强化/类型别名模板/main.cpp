#include <iostream>

template<typename T, typename U>
class MagicType
{
public:
    T dark;
    U magic;
};

// 不合法
// typedef MagicType<int, int> FakeDarkMagic;

typedef int MyInt;
using MyInt = int;
using TureDarkMagic = MagicType<int, int>;

int main()
{
    TureDarkMagic you;
}