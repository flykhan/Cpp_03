#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main()
{
    string condidates[] = {
        "syl@syl.com", "01SYL@syl.com.cn", "_syl@163.com", "syl.com", "sly@.sly.com"};
    // 补充email_regex 的参数即可
    regex email_regex("[a-zA-Z][a-zA-Z0-9_]*@[^.][a-z0-9.]+");
    for (const auto &con : condidates)
    {
        if (regex_match(con, email_regex))
            cout << "\"" << con << "\""
                 << " is a valid email address." << endl;
        else
            cout << "\"" << con << "\""
                 << " is not a valid email address." << endl;
    }
}