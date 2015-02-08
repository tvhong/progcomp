#include <cstdio>
#include <iostream>
#include <string>

using namespace std;
string s;
int main() {
    cin >> s;
    int i, lasteven = -1;
    bool good = false;
    for (i=0; i<s.length(); i++) {
        int j = s[i] - '0';
        if (!(j & 1) && s[i] < s[s.length()-1]) {
            swap(s[i], s[s.length()-1]);
            good = true;
            break;
        }
        if (!(j & 1)) {
            lasteven = i;
        }
    }
    //printf("lasteven = %d\n", lasteven);

    if (i == s.length() && lasteven != -1) {
        swap(s[lasteven], s[s.length()-1]);
        good = true;
    }
    printf("%s\n", (!good) ? "-1" : s.c_str());

    return 0;
}
