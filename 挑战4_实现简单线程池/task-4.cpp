#include <iostream>
#include <vector>
#include <chrono>
#include "ThreadPool.h"
using namespace std;

int main()
{
    ThreadPool pool(4);
    vector<future<int>> results;

    for(int i = 0; i < 8; ++i){
        // emplace_back () ：在容器尾部添加一个元素，调用 构造函数 原地构造，不需要触发拷贝构造和移动构造。 因此比 push_back () 更加高效。
        results.emplace_back(
            pool.enqueue([i] {
                cout << "hello" << i << endl;
                this_thread::sleep_for(chrono::seconds(1));
                cout << "world" << i << endl;
                return i*i;
            })
        );
    }

    for (auto && result : results)
        cout << result.get() << ' ';
    cout << endl;

    return 0;
}
