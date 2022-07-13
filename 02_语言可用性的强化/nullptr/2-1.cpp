#include <iostream>
#include <type_traits> // traits: 特点，性状
using namespace std;

void foo(char *);
void foo(int);

int main()
{
    if (is_same<decltype(NULL), decltype(0)>::value)
        cout << "NULL == 0" << endl;
    if (is_same<decltype(NULL), decltype((void *)0)>::value)
        cout << "NULL == (void *)0" << endl;
    if (is_same<decltype(NULL), nullptr_t>::value)
        cout << "NULL == nullptr" << endl;

    foo(0); // 调用 foo(int)
    // foo(NULL); // 不可编译
    foo(nullptr); // 调用 foo(char*)
    return 0;
}

void foo(char *)
{
    cout << "foo(char*) is called" << endl;
}

void foo(int i)
{
    cout << "foo(int) is called" << endl;
}