#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  string res;
  int cnt = 0;
  while (n > 0 && m > 0) {
    if (cnt == 2) res += "0", n--;
    else res.push_back('1'), m--;
    cnt = (cnt+1)%3;
  }
  if (n == 0)
    if (m <= 2) {
      for (int i=0; i<m; i++)
        res.push_back('1');
      m = 0;
    }
  cnt = 0;
  if (m==0) {
    int i = 0;
    //cout << n << endl;
    while (n > 0 && i < res.size()) {
      if (i > 0 && res[i-1] == '0') i++;
      if (i >= res.size()) break;
      res.insert(i++, "0");
      n--;
    }
    if (n)
      res.push_back('0'), n--;
  }
  //printf("n=%d m=%d res=%s\n", n, m, res.c_str());
  printf("%s\n", (n==0 && m==0) ? res.c_str() : "-1");
  return 0;
}
