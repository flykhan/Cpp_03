#include <iostream>
#include <map>
#include <functional>
using namespace std;

template <typename Key, typename Value, typename F>
void update(map<Key, Value>& m, F foo)
{
    // TODO:
    for (auto&& [key, value] : m) value = foo(key);
}

int main()
{
    map<string, long long int> m {
        {"a", 1},
        {"b", 2},
        {"c", 3}
    };

    update(m, [](string key) -> long long int {
        return hash<string>{}(key);
    });

    for (auto&& [key, value] : m) {
        cout << key << ":" << value << endl;
    }

    return 0;
}