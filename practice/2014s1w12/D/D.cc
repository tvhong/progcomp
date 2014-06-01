#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MOD = 1e9+7;
typedef unsigned long long ll;
int n;

int main() {
  while (scanf("%d", &n), n) {
    ll ans = 1;
    for (int i=1; i*i<=n; i++) {
      ans = (ans*i*i) % MOD;
    }
    cout << ans << endl;
  }
  return 0;
}
