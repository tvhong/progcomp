#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 1e7+5;
const int MOD = 1e9+7;
typedef long long ll;
int n, not_prime[N], primes[N], p;
ll d;

ll po(ll p, ll q) {
  if (q == 0) return 1;
  ll tmp = po(p, q/2);
  ll ans = (tmp * tmp) % MOD;
  if (q&1) {
    ans = (ans * p) % MOD;
  }
  return ans;
}

int main() {
  memset(not_prime, 0, sizeof not_prime);
  for (ll i = 2; i <= N; i++) {
    if (not_prime[i]) continue;
    primes[p++] = i;
    for (ll tmp = i; tmp <= N; tmp += i) {
      not_prime[tmp] = 1;
    }
  }
  //printf("%d\n", primes[p-1]);
  while (scanf("%d", &n), n) {
    d = 1;
    for (ll i = 0; i < p && primes[i] <= n; i++) {
      ll q = 0;
      for (ll tmp = primes[i]; tmp <= n; tmp *= primes[i]) {
        q += n / tmp;
      }
      //cout << "primes[i]=" << primes[i] << " q=" << q; 
      if (q&1) q--;
      d = (d * po(primes[i], q)) % MOD;
      //cout << " d=" << d << endl;
    }
    cout << d << endl;
  }
  return 0;
}
