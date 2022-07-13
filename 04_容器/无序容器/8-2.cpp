#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;

int main()
{
    unordered_map<int, string> u =
        {
            {1, "1"},
            {2, "2"},
            {3, "3"}};

    map<int, string> v =
        {
            {1, "1"},
            {2, "2"},
            {3, "3"}};

    cout << "unordered_map" << endl;
    for (const auto &n : u)
    {
        cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
    }
    cout << endl;

    cout << "map" << endl;
    for (const auto &n : v)
    {
        cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
    }
    cout << endl;

    return 0;
}