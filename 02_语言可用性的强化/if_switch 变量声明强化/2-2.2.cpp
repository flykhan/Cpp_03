#include <iostream>
#include <vector>
#include <algorithm> // algorithm ：算法
using namespace std;

int main()
{
    vector<int> vec = {1, 2, 3, 4};

    const vector<int>::iterator itr = find(vec.begin(), vec.end(), 2);
    if (itr != vec.end())
    {
        // 将第三个值换成 3
        *itr = 3;
    }

    // 将临时变量放到 if 语句内
    if (const vector<int>::iterator itr = find(vec.begin(), vec.end(), 3);
        itr != vec.end())
    {
        // 将第四个值换成 4
        *itr = 4;
    }

    // 将输出 1, 4, 3, 4
    for (vector<int>::iterator element = vec.begin(); element != vec.end(); ++element)
    {
        cout << *element << endl;
    }
}