#include <bits/stdc++.h>

#define x first
#define y second
#define mp make_pair

using namespace std;
const int N = 1005;
const int INF = 1e6;

int m, to[2*N], next[2*N], last[N];
void add_edge(int u, int v) {
  to[m] = v;
  next[m] = last[u];
  last[u] = m++;
}
int deleted[N], pass[N], deg[N], ans, n, T;
void init() {
  m = 0;
  memset(last, -1, sizeof last);
  ans = 0;
  for (int i=0; i<N; i++) {
    deleted[i] = 0;
    pass[i] = 0;
    deg[i] = 0;
  }
}

void solve() { 
  int ndeg2 = 0;
  ans = 0;
  for (int u=1; u<=n; u++)
    if (deg[u] == 2) ndeg2++;

  for (int i=0; i<n; i++)
    for (int u=1; u<=n; u++) {
      if (pass[u] || deleted[u]) continue;
      if (deg[u] == 1) {
        //printf("u=%d\n", u);
        for (int e = last[u]; ~e; e = next[e]) {
          int v = to[e];
          if (deleted[v]) continue;
          if (deg[v] != 3) {
            //printf("v=%d, ndeg2=%d\n", v, ndeg2);
            if (deg[v] == 2 && ndeg2 == 1) {
              pass[u] = 1;
            } else {
              //printf("del\n");
              deleted[u] = 1;
              if (deg[v] == 2) ndeg2--;
              deg[v]--;
              ans++;
            }
          }
        }
      }
    }
  DFS(1);
  if (ndeg2 == 0) ans++;
  for (int u=1; u<=n; u++) {
    printf("u=%d, deg[u] = %d\n", u, deg[u]);
  }
}

int main() {
  scanf("%d", &T);
  for (int t=1; t<=T; t++) {
    init();
    printf("Case #%d: ", t);
    scanf("%d", &n);
    for (int i=0; i<n-1; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      add_edge(u, v);
      add_edge(v, u);
      deg[u]++;
      deg[v]++;
    }
    solve();
    printf("%d\n", ans);
  }
  return 0;
}
