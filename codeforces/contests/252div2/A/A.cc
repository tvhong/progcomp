#include <cstdio>
#include <vector>
#include <algorithm>

const int N = 100;
int n, v, cnt;
int sellers[N];

int main() {
  scanf("%d %d", &n, &v);
  for (int i=1; i<=n; i++) {
    int m, x;
    scanf("%d", &m);
    for (int j=0; j<m; j++) {
      scanf("%d", &x);
      if (x < v && !sellers[i]) {
        cnt++;
        sellers[i] = 1;
      }
    }
  }
  printf("%d\n", cnt);
  bool printed = false;
  for (int i=1; i<=n; i++) {
    if (sellers[i]) {
      if (printed) printf(" ");
      printf("%d", i);
      printed = true;
    }
  }
  printf("\n");
  return 0;
}
