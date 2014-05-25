#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;
const int N = 1005;

int n, a[N], T, k;

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &k);
    for (int i=0; i<n; i++)
      scanf("%d", &a[i]);
    ll minval = 1e12;
    int cnt = 0;
    for (int i=0; i<n; i++) 
      for (int j=i+1; j<n; j++) {
        ll val = abs(a[j] + a[i] - k);
        if (val < minval) {
          minval = val;
          cnt = 1;
        } else if (minval == val) {
          cnt++;
        }
      }
    printf("%lld %d\n", minval, cnt);
  }
  return 0;
}
