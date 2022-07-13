#include <iostream>
#include <memory>
using namespace std;

struct A;
struct B;

struct A
{
    weak_ptr<B> pointer;
    ~A() { cout << "A 被销毁" << endl; }
};
struct B
{
    shared_ptr<A> pointer;
    ~B() { cout << "B 被销毁" << endl; }
};

int main()
{
    auto a = make_shared<A>();
    auto b = make_shared<B>();
    a->pointer = b;
    b->pointer = a;
}
