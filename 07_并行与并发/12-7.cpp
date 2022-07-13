#include <iostream>
#include <thread>
#include <atomic>
#include <vector>
#include <ctime>

#define THREAD_NUM 1000
using namespace std;

auto relaxed_model()
{
    atomic<int> counter = {0};
    vector<thread> vt;
    for (int i = 0; i < THREAD_NUM; ++i)
    {
        vt.emplace_back([&]()
                        { counter.fetch_add(1, memory_order_relaxed); });
    }
    for (auto &t : vt)
    {
        t.join();
    }
    cout << "current counter:" << counter << endl;
}

auto seq_cst_model()
{
    atomic<int> counter = {0};
    vector<thread> vt;
    for (int i = 0; i < THREAD_NUM; ++i)
    {
        vt.emplace_back([&]()
                        { counter.fetch_add(1, memory_order_seq_cst); });
    }
    for (auto &t : vt)
    {
        t.join();
    }
    cout << "current counter:" << counter << endl;
}

int main()
{
    clock_t start1 = clock();
    relaxed_model();
    cout << "宽松模型用时: " << (((double)clock() - start1) / CLOCKS_PER_SEC) << endl;

    clock_t start2 = clock();
    seq_cst_model();
    cout << "顺序模型用时: " << (((double)clock() - start2) / CLOCKS_PER_SEC) << endl;
}