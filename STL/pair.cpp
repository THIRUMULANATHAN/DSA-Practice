#include <iostream>

using namespace std;

int main () {
    // pair <int, string> p;

    // p = make_pair(53, "Thiru");
    // p = {1, "Abdul"};

    // p.first = 2;

    // cout << p.first << " " << p.second;


    pair <string, pair<string, string>> dp;
    dp = make_pair("Thiru", make_pair("Web Dev", "Electrical Engineer"));

    cout << dp.first << "\n";
    cout << dp.second.first << "\n";
    cout << dp.second.second << "\n";

    return 0;
}