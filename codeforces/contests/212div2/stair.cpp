#include <bits/stdc++.h>

using namespace std;
int main() {
  int n, m;
  int a[3000];

  scanf("%d%d", &n, &m);
  for (int i=0; i<m; i++) {
    scanf("%d", &a[i]);
    if (a[i] == 1 || a[i] == n) {
      printf("NO\n");
      return 0;
    }
  }
  sort(a, a+m); 
  int cnt=1;
  for (int i=1; i<m; i++) {
    if (a[i] - a[i-1] == 1) {
      cnt++;
    } else {
      cnt = 1;
    }
    if (cnt >= 3) {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  return 0;
}
