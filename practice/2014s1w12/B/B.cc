#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;
int n, m, l, r, left[N], right[N];
int main() {
  while(scanf("%d %d", &n, &m), !(n == 0 && m == 0)) {
    for (int i=1; i<=n; i++) {
      left[i] = i-1;
      right[i] = i+1;
    }
    left[1] = -1;
    right[n] = -1;

    for (int i=0; i<m; i++) {
      scanf("%d %d", &l, &r);
      if (left[l] != -1) {
        printf("%d ", left[l]);
        right[left[l]] = right[r];
      } else {
        printf("* ");
      }
      if (right[r] != -1) {
        printf("%d\n", right[r]);
        left[right[r]] = left[l];
      } else {
        printf("*\n");
      }
    }
    printf("-\n");
  }
  return 0;
}
