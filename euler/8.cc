#include <bits/stdc++.h>

using namespace std;
const int N = 1000;

int main() {
  char str[N+5];
  int maxn = 0;
  scanf("%s", str);
  for (int i = 0; i <= strlen(str) - 5; i++) {
    int n = 1;
    for (int j = 0; j < 5; j++) {
      n *= (str[i+j] - '0');
    }
    maxn = max(n, maxn);
  }
  printf("%d\n", maxn);
  return 0;
}
