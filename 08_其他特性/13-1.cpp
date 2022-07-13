#include <iostream>
using namespace std;

void may_throw()
{
    throw true;
}
void no_throw() noexcept
{
    return;
}
auto non_block_throw = []
{
    may_throw();
};
auto block_throw = []() noexcept
{
    may_throw();
};

int main()
{
    cout << "\n--- noexcept test ---\n"
         << endl;
    cout << boolalpha << "may_throw() noexcept? " << noexcept(may_throw()) << endl
         << "no_throw() noexcept? " << noexcept(no_throw()) << endl
         << "non_block_throw() noexcept? " << noexcept(non_block_throw()) << endl
         << "block_throw() noexcept? " << noexcept(block_throw()) << endl;

    cout << "\n--- try...catch... test ---\n"
         << endl;
    try
    {
        may_throw();
    }
    catch (...)
    {
        cout << "捕获异常,来自 my_throw()" << endl;
    }
    try
    {
        non_block_throw();
    }
    catch (...)
    {
        cout << "捕获异常,来自 non_block_throw()" << endl;
    }
    try
    {
        block_throw();
    }
    catch (...)
    {
        cout << "捕获异常,来自 block_throw()" << endl;
    }
    return 0;
}