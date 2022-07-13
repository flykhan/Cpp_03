#include <iostream>
#include <vector>
#include <thread>
#include <atomic>
using namespace std;

int main()
{
    vector<int> v;
    atomic<int> flag = {0};
    thread release([&]()
                   {
            v.push_back(42);
            flag.store(1,memory_order_release); });

    thread acqrel([&]()
                  {
            int expected = 1; // must before compare_exchange_strong

            while (!flag.compare_exchange_strong(expected, 2, memory_order_acq_rel))
            {
                expected = 1; // must after compare_exchange_strong
            }
            // flag has changed to 2 
            });

    thread acquire([&]()
                   {
                       while (flag.load(memory_order_acquire) < 2);
                       cout << v.at(0) << endl; // must be 42 
                       });
    release.join();
    acqrel.join();
    acquire.join();
}