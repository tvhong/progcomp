#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
map<int, ll> cache;
ll cal(int n) {
  if (cache[n] != 0) return cache[n];
  ll res = n;
  if (n & 1) {
    res = max(res, cal(n*3 + 1));
  } else {
    res = max(res, cal(n>>1));
  }
  return cache[n] = res;
}

int main() {
  int t, i, n;
  scanf("%d", &t);
  cache[1] = 1;
  cache[2] = 2;
  cache[4] = 4;
  while(t--) {
    scanf("%d %d", &i, &n);
    printf("%d %lld\n", i, cal(n));
  }
  return 0;
}
