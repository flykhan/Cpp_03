#include <iostream>
#include <vector>
#include <algorithm> // algorithm: 算法
using namespace std;

int main()
{
    vector<int> vec = {1, 2, 3, 4};
    if (auto itr = find(vec.begin(), vec.end(), 3); itr != vec.end())
        *itr = 4;
    for (auto element : vec)
    {
        // read only
        cout << element << endl;
    }

    // & 启用了引用, 如果没有则对 vec 中的元素只能读取不能修改
    for (auto &element : vec)
    {
        // writeable
        element += 1;
    }
}