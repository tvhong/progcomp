#include <cstdio>

const int N = 2005;
int main() {
  int n, a[N];
  scanf("%d", &n);
  for (int t=1; t<=n; t++) {
    int c, L;
    scanf("%d", &c);
    scanf("%d", &L);
    for (int i=0; i<L; i++) {
      scanf("%d", &a[i]);
    }
    printf("Case #%d: ", t);
    for (int i=0; i<L; i++) {
      for (int j=i+1; j<L; j++) {
        if (a[i] + a[j] == c) {
          printf("%d %d", i+1, j+1);
          goto hell;
        }
      }
    }
hell:
    printf("\n");
  }
  return 0;
}
