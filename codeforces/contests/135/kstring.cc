#include <bits/stdc++.h>

using namespace std;

const int L = 26;
int k;
int al[L];
int main() {
  string str;
  cin >> k >> str;
  for (int i=0; i<str.size(); i++) {
    al[str[i]-'a']++;
  }
  bool good = true;
  string s;
  for (int i=0; i<L && good; i++) {
    if (al[i] % k != 0)
      good = false;
    else {
      for (int j=0; j < al[i]/k; j++) {
        s.push_back(i+'a');
      }
    }
  }
  if (good) {
    string res;
    for (int i=0; i<k; i++) {
      res += s;
    }
    cout << res << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}
