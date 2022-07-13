// 原始代码

#include <iostream>
#include <map>
using namespace std;

template <typename Key, typename Value, typename F>
void update(map<Key, Value> &m, F foo)
{
    // TODO:
}

int main()
{
    map<string, long long int> m{
        {"a", 1}, {"b", 2}, {"c", 3}};
    update(m, [](string key)
           { return hash<string>{}(key); });
    for (auto &&[key, value] : m)
        cout
            << key << ":" << value << endl;

    return 0;
}
