#include <atomic>
#include <thread>
#include <iostream>
using namespace std;

atomic<int> co = {0};

int main()
{
    // 输出 count 是否可以转换为指令级的原子操作
    cout << boolalpha << co.is_lock_free() << endl;

    thread t1([]()
              { co.fetch_add(1); });
    thread t2([]()
              {
        co++; // 等价于 fetch_add
        co+=1; }); // 等价于 fetch_add

    t1.join();
    t2.join();
    cout << co << endl;
    return 0;
}