#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e3+5;
int T, n, a[N], dp[N][N];
bool re(int s, int i) {
  printf("calling re on %d %d\n", s, i);
  if (dp[s][i] != -1) return dp[s][i];
  bool res = re(s, i-1) || re((s-a[i]+n)%n, i-1);
  return dp[s][i] = res;
}
void solve() {
  for (int i=0; i<=n; i++)
    dp[0][i] = true;
  for (int i=0; i<=n; i++)
    dp[i][0] = false;
  bool good = re(0, n-1);
  printf("%s\n", good ? "yes" : "no");
}

int main() {
  scanf("%d", &T);
  while (T--) {
    for (int i=0; i<N; i++)
      memset(dp[i], -1, sizeof dp[i]);
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
      scanf("%d", &a[i]);
      a[i] %= n;
    }
    solve();
  }
  return 0;
}
