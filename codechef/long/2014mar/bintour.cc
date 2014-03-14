#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll K = 20;
const ll N = 1 << K;
const ll MOD = 1e9 + 9;
ll k, n, ans, fact[N+5];

ll choose(ll n, ll k) {
  return (fact[n] / ((fact[k]*fact[n-k])%MOD))%MOD;
}

int main() {
  scanf("%lld", &k);
  n = 1 << k;
  fact[0] = fact[1] = 1;
  for (ll i=2;i<=n;i++)
    fact[i] = (fact[i-1]*i)%MOD;

  for (ll i=1;i<=n;i++) {
    //printf("i=%lld\n", i);
    ll weaker = i-1;
    if (weaker >= n/2-1) {
      ll ans = choose(weaker, n/2 - 1);
      ans = (ans * fact[n/2])%MOD;
      ans = (ans * fact[n/2])%MOD;
      ans = (ans * 2)%MOD;
      printf("%lld\n", ans);
    }
    else
      printf("0\n");
  }
  return 0;
}
