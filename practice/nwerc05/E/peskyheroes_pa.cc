/* Solution to "Pesky Heroes" from NWERC 05
 * Author: Per Austrin */
#include <cstring>
#include <cstdio>
const int I = 0xDeadbeef;
int adj[55555][5], n, m, k;
int f(int x, int y, int z) { return x == y ? z : y; }
int o(int x)  { return x != I ? x < 0 ? -x : x : 1; }
int a(int x, int y) {
  return x==I ? y < 0 ? y==I ? I : y : -y-1 : y==I ? a(y, x) : o(x) + o(y);
}
int rcs(int v, int par) {
  return adj[v][0] >= 0 ? adj[v][1] >= 0 ? adj[v][2] >= 0 ?
    a(rcs(f(par,adj[v][0],adj[v][2]), v), rcs(f(par,adj[v][1],adj[v][2]), v)) 
    : rcs(f(par,adj[v][0],adj[v][1]), v) : I : 0;
}
int main(void) {
  for (; scanf("%d%d", &n, &m)==2 && n+m; printf("%d\n", o(rcs(**adj, 0)))) {
    memset(adj, -1, sizeof(adj));
    for (int i = 0; i < n && scanf("%d", &k); ++i)
      for (int j = 0; j < k; ++j) scanf("%d", adj[i]+j), --adj[i][j];
    for (int i = 0; i < m && scanf("%d", &k); ++i) *adj[--k] = -1;
  }
  return 0;
}
