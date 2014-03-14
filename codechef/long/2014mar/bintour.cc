#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll K = 20;
const ll N = 1 << K;
const ll MOD = 1e9 + 9;
ll k, n, ans, fact[N+5];

ll mpow(ll n, ll p) {
  ll res = 1;
  ll base = n;
  while (p) {
    if (p & 1) {
      res = (res * base) % MOD;
    }
    base = (base * base) % MOD;
    p >>= 1;
  }
  return res;
}

ll mpow2(ll n, ll p) {
  if (p == 0) return 1;
  ll a = mpow2(p/2);
  return (p&1) ? a*a*n : a*a*;
}

ll inv(ll n) {
  return mpow(n, MOD - 2)%MOD;
}

ll choose(ll n, ll k) {
  return (fact[n] * inv((fact[k]*fact[n-k])%MOD))%MOD;
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
