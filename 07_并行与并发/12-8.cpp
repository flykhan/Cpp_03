#include <iostream>
#include <thread>
#include <atomic>
using namespace std;

int main()
{
    // 初始化为 nullptr 防止 consumer 线程从野指针进行读取
    atomic<int *> ptr(nullptr);
    int v;
    thread producer([&]()
                    {
        int* p = new int(42);
        v = 1024;
        ptr.store(p,memory_order_release); });

    thread consumer([&]()
                    {
        int* p;
        while (!(p = ptr.load(memory_order_consume)));
        cout << "p" << *p << endl;
        cout << "v" << v << endl; });

    producer.join();
    consumer.join();
}