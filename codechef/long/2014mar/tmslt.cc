#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 3e6;
ll T, n, s[N+5];
ll a, b, c, d;
int main() {
  scanf("%lld", &T);
  while (T--) {
    scanf("%lld %lld %lld %lld %lld", &n, &a, &b, &c, &d);
    for (ll i=0; i<N; i++)
      s[i] = 0;
    ll val = d;
    s[val]++;
    for (ll i=1; i<n; i++) {
      val = (a*val*val + b*val + c) % 1000000;
      s[val]++;
    }
    ll t1 = 0, t2 = 0;
    int one = 0;
    for (ll i=0; i<N; i++)
      while (s[i] > 0) {
        one ^= 1;
        if (one)
          t1 += i;
        else
          t2 += i;
        s[i]--;
      }
    //printf("%lld %lld\n",t1 , t2);
    printf("%lld\n", abs(t1 - t2));
  }
  return 0;
}
