#include <cstdio>

int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    int tmp = 5, ans = 0;
    scanf("%d", &n);
    while (n >= tmp) {
      ans += n / tmp;
      tmp *= 5;
    }
    printf("%d\n", ans);
  }
  return 0;
}
