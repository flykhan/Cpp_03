#include <initializer_list>
#include <vector>
#include <iostream>
using namespace std;

class MagicFoo
{
public:
    vector<int> vec;
    MagicFoo(initializer_list<int> list)
    {
        // 从 C++11起，使用 auto 关键字进行类型推导
        for (auto it = list.begin(); it != list.end(); ++it)
        {
            vec.push_back(*it);
        }
    }
};

int main()
{
    MagicFoo magicFoo = {1, 2, 3, 4, 5};
    cout << "magicFoo: ";
    for (auto it = magicFoo.vec.begin(); it != magicFoo.vec.end(); ++it)
    {
        cout << *it << ", ";
    }
    cout << endl;
    return 0;
}