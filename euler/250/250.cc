#include <cstdio>
#include <cstring>
#include <algorithm>

typedef long long ll;
const ll MOD = (ll)(1e16);
const int N = 250;

int n;
ll dp[N], tmp[N];

int fastpow(int base, int pow, int mod) {
  if (!pow) return 1;
  ll tmp = fastpow(base, pow>>1, mod);
  return (pow & 1) ? (tmp * tmp * base)%mod : (tmp * tmp)%mod;
}

int main() {
  scanf("%d", &n);
  //printf("%d\n", fastpow(2, n, N));
  memset(dp, 0, sizeof dp);
  for (int i=1; i<=n; i++) {
    int val = fastpow(i, i, N);
    memcpy(tmp, dp, sizeof dp);
    for (int j=0; j<N; j++) {
      dp[j] = (dp[j] + tmp[(j + N - val) % N]) % MOD;
    }
    dp[val] = (dp[val] + 1) % MOD;
  }
  for (int i=0; i<N; i++) {
    printf("dp[%d] = %lld\n", i, dp[i]);
  }

  return 0;
}
