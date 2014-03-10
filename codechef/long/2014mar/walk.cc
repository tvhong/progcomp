#include <bits/stdc++.h>

using namespace std;
int main() {
  int T, n;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    int nmax = 0;
    int a;
    for (int i=0;i<n;i++) {
      scanf("%d", &a);
      nmax = max(nmax, a+i);
    }
    printf("%d\n", nmax);
  }
  return 0;
}
