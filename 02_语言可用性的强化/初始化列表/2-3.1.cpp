#include <iostream>
#include <vector>
using namespace std;

class Foo
{
public:
    int value_a;
    int value_b;

public:
    Foo(int a, int b) : value_a(a), value_b(b) {}
};

int main()
{
    // before C++11
    int arr[3] = {1, 2, 3};
    Foo foo(1, 2);
    vector<int> vec = {1, 2, 3, 4, 5};

    Foo foo2{3, 4};
    cout << "foo2: " << foo2.value_a << ", " << foo2.value_b << endl;

    cout << "arr[0]: " << arr[0] << endl;
    cout << "foo: " << foo.value_a << ", " << foo.value_b << endl;
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        cout << *it << endl;
    }

    return 0;
}