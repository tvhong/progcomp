#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
const int N = 1e5;
int n;
int main() {
    string s;
    cin >> s;
    int val;
    if (s.size() == 1) {
        val = s[0] - '0';
    } else {
        val = (s[s.size()-2]-'0') * 10 + (s[s.size()-1] - '0');
    }
    printf("%d\n", (val % 4 == 0) ? 4 : 0);
    return 0;
}
