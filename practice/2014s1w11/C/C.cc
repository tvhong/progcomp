#include <cstdio>
#include <cstring>

using namespace std;

const int N = 2*1e6 + 5;
int n, ans;
int a[N], danger[N];
int main() {
  while (scanf("%d", &n), n) {
    memset(danger, 0, sizeof danger);
    for (int i=0; i<n; i++) {
      scanf("%d", &a[i]);
      a[n+i] = a[i];
    }
    int val = 0;
    for (int i=2*n-1; i>=0; i--) {
      val += a[i];
      if (val < 0) danger[i] = true;
      else val = 0;
    }
    ans = 0;
    for (int i=0; i<n; i++)
      if (!danger[i]) ans++;
    printf("%d\n", ans);
    /*
    for (int i=0; i<2*n; i++)
      printf("%3d", a[i]);
    printf("\n");
    for (int i=0; i<2*n; i++)
      printf("%3d", danger[i]);
    printf("\n");
    */
  }

  return 0;
}
