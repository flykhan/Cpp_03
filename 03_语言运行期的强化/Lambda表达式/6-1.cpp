#include <iostream>
using namespace std;

void lambda_value_capture()
{
    int value = 1;
    auto copy_value = [value]
    {
        return value;
    };
    value = 100;
    auto stored_value = copy_value();
    cout << "stored_value = " << stored_value << endl;
}

void lambda_referance_capture()
{
    int value = 1;
    auto copy_value = [&value]
    {
        return value;
    };
    value = 100;
    auto stored_value = copy_value();
    cout << "stored_value = " << stored_value << endl;
}

int main()
{
    lambda_value_capture();
    lambda_referance_capture();
    return 0;
}