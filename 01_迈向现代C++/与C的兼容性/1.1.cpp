#include "foo.h"
#include <iostream>
#include <functional>
using namespace std;
int main()
{
    // 这句没有错，换Cpp Standard为c++20试试
    [out = ref(cout << "Result from C code: " << add(1, 2))]()
    {
        out.get() << ".\n";
    }();
    return 0;
}