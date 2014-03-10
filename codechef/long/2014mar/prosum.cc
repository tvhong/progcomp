#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int T, n, num, g2, e2;
ll ans;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    g2 = 0;
    e2 = 0;
    ans = 0;
    for (int i=0; i<n;i++) {
      scanf("%d", &num);
      if (i > 0) {
        if (num > 2)
          ans += g2 + e2;
        else if (num == 2)
          ans += g2;
      }
      if (num > 2)
        g2++;
      else if (num == 2)
        e2++;
    }
    printf("%lld\n", ans);
  }
  return 0;
}

