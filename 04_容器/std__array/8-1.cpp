#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    cout << "size:" << v.size() << endl;         // 输出 0
    cout << "capacity:" << v.capacity() << endl; // 输出 0

    // 如下可看出 std::vector 的存储是自动管理的，按需自动扩张
    // 但是如果空间不足，需要重新分配更多内存，而重分配内存通常是性能上有开销的操作
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    cout << "size:" << v.size() << endl;         // 输出 3
    cout << "capacity:" << v.capacity() << endl; // 输出 4

    // 这里的自动扩张逻辑与 Golang 的 slice 很像

    v.push_back(4);
    v.push_back(5);
    cout << "size:" << v.size() << endl;         // 输出 5
    cout << "capacity:" << v.capacity() << endl; // 输出 8

    // 如下可看出容器虽然清空了元素，但是被清空元素的内存并没有归还
    v.clear();
    cout << "size:" << v.size() << endl;         // 输出 0
    cout << "capacity:" << v.capacity() << endl; // 输出 8

    // 额外内存可通过 shrink_to_fit() 调用返回给系统
    v.shrink_to_fit();
    cout << "size:" << v.size() << endl;         // 输出 0
    cout << "capacity:" << v.capacity() << endl; // 输出 0

    return 0;
}