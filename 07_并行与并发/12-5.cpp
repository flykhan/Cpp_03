#include <thread>
#include <iostream>
using namespace std;

int main()
{
    int a = 0;
    int flag = 0;

    thread t1([&]()
              {
        while (flag != 1);

        int b = a;
        cout << "b = " << b << endl; });

    thread t2([&]()
              {
        a = 5;
        flag = 1; });

    t1.join();
    t2.join();
    return 0;
}