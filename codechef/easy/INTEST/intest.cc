#include <cstdio>

int main() {
  int n, k, a, ans = 0;
  scanf("%d %d", &n, &k);
  for (int i=0; i<n; i++) {
    scanf("%d", &a);
    if (a%k==0) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
