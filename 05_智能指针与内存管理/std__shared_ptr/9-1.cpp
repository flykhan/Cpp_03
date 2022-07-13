#include <iostream>
#include <memory>
using namespace std;

void foo(shared_ptr<int> i)
{
    (*i)++;
}

int main()
{
    // auto pointer = new int(10); // 不合法
    // 创建类型为 std::shared_ptr
    auto pointer = make_shared<int>(10);
    foo(pointer);
    cout << *pointer << endl; // 11

    // 共享指针在离开作用域前会被析构掉

    auto pointer2 = pointer;                                           // 引用计数 +1
    auto pointer3 = pointer;                                           // 引用计数 +1
    int *p = pointer.get();                                            // 这样不会增加
    cout << "pointer.use_count() = " << pointer.use_count() << endl;   // 3
    cout << "pointer2.use_count() = " << pointer2.use_count() << endl; // 3
    cout << "pointer3.use_count() = " << pointer3.use_count() << endl; // 3

    pointer2.reset();
    cout << "reset pointer2:" << endl;
    cout << "pointer.use_count() = " << pointer.use_count() << endl;   // 2
    cout << "pointer2.use_count() = " << pointer2.use_count() << endl; // 0，pointer2 已经被 reset
    cout << "pointer3.use_count() = " << pointer3.use_count() << endl; // 2
    pointer3.reset();
    cout << "reset pointer3:" << endl;
    cout << "pointer.use_count() = " << pointer.use_count() << endl;   // 1
    cout << "pointer2.use_count() = " << pointer2.use_count() << endl; // 0
    cout << "pointer3.use_count() = " << pointer3.use_count() << endl; // 0，pointer3 已经被 reset

    return 0;
}