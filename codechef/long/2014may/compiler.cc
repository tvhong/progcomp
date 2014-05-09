#include <bits/stdc++.h>

using namespace std;

const int L = 1e6;
int T;

string str;
int main() {
  cin >> T;
  while (T--) {
    stack<char> st;
    cin >> str;
    int ans = 0;
    for (int i=0; i<str.length(); i++) {
      if (str[i] == '<') {
        st.push(i);
      } else {
        assert(str[i] == '>');
        if (!st.empty()) {
          st.pop();
          if (st.empty()) ans = i+1;
        } else {
          break;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
