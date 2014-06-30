#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 50005;
const int M = N*2;
int trap[N], n, m, ntrap[N], hasleave[N], seen[N], ans, valid[N];

int E, to[M], nex[M], start[N];
void add_edge(int u, int v) {
  to[E] = v;
  nex[E] = start[u];
  start[u] = E++;
}

void init() {
  E = 0;
  memset(start, -1, sizeof start);
  memset(trap, 0, sizeof trap);
  memset(ntrap, 0, sizeof ntrap);
  memset(hasleave, 0, sizeof hasleave);
  memset(valid, 0, sizeof valid);
  ans = 0;
}

void build(int from, int u) {
  //printf("visiting %d\n", u);
  if (seen[u]) return;
  seen[u] = 1;
  if (trap[u]) {
    valid[u] = 0;
    ntrap[u] = 1;
    hasleave[u] = 0;
    return;
  }
  for (int e = start[u]; ~e; e = nex[e]) {
    int v = to[e];
    if (v == from) continue;
    build(u, v);
    if (valid[v]) {
      ntrap[u] += ntrap[v];
      hasleave[u] = hasleave[u] || hasleave[v];
    } else {
      ntrap[u]++;
    }
  }

  valid[u] = (ntrap[u] < 2 && hasleave[u]);
  for (int e = start[u]; ~e; e = nex[e]) {
    int v = to[e];
    if (v == from) continue;
    if (!valid[u] && valid[v]) ans++;
  }
  if (u == 1 && valid[u]) ans++;
}

void solve() {
  memset(seen, 0, sizeof seen);
  build(-1, 1);
  printf("%d\n", ans);
}

int main() {
  while (scanf("%d %d", &n, &m), !(n == 0 && m == 0)) {
    init();
    for (int i=1; i<=n; i++) {
      int k;
      scanf("%d", &k);
      hasleave[i] = (i > 1 && k == 1);
      for (int j=0; j<k; j++) {
        int x;
        scanf("%d", &x);
        add_edge(i, x);
      }
    }
    for (int i=0; i<m; i++) {
      int x;
      scanf("%d", &x);
      trap[x] = 1;
    }
    solve();
  }
  return 0;
}
