#include <cstdio>

const int N = 100 + 5;
int a[N];
int n, al, ar, l, r;

int main() {
  scanf("%d", &n);
  scanf("%d %d", &al, &ar);
  for (int i=1; i<n; i++) {
    scanf("%d %d", &l, &r);
    for (int j=l; j<r; j++) {
      a[j] = 1;
    }
  }
  int ans = 0;
  for (int i=al; i<ar; i++) {
    if (!a[i]) {
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
