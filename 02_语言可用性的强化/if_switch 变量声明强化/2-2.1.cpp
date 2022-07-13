#include <iostream>
#include <vector>
#include <algorithm> // algorithm ：算法
using namespace std;

int main()
{
    vector<int> vec = {1, 2, 3, 4};

    // 在 C++17 之前
    const vector<int>::iterator itr = find(vec.begin(), vec.end(), 2);
    if (itr != vec.end())
    {
        *itr = 3;
    }

    // 需要重新定义一个新的变量
    const vector<int>::iterator itr2 = find(vec.begin(), vec.end(), 3);
    if (itr2 != vec.end())
    {
        *itr2 = 4;
    }

    // 将输出 1, 4, 3, 4
    for (vector<int>::iterator element = vec.begin(); element != vec.end(); ++element)
    {
        cout << *element << endl;
    }
}