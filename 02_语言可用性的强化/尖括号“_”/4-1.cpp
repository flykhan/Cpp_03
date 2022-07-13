#include <iostream>
#include <vector>
using namespace std;

template <bool T>
class MagicType
{
public:
    bool value = T;
};

int main()
{
    // 合法，但不建议写出这样的代码
    vector<MagicType<(1 > 2)>> magic;

    MagicType<(2 > 3)> m1;
    magic.push_back(m1);
    for (auto itr = magic.begin(); itr < magic.end(); ++itr)
    {
        cout << itr->value << endl;
    }
    return 0;
}