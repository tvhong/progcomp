#include <cstdio>
#include <cstring>

using namespace std;

const int N = 2014;
const int M = N*N;
int n, m;
int inv(int i) {
  return (i + n) % (2*n);
}

int E, start[N], succ[M], to[M];
int E_r, start_r[N], succ_r[M], to_r[M];
void add_edge(int u, int v) {
  //printf("add_edge %d %d\n", u, v);
  to[E] = v;
  succ[E] = start[u];
  start[u] = E++;

  to_r[E_r] = u;
  succ_r[E_r] = start_r[v];
  start_r[v] = E_r++;
}

int seen[N], seen_r[N], scc[N], postorder[N], p;

void dfs(int u) { 
  if (seen[u]) return; 
  seen[u] = true; 
  for (int e = start[u]; ~e; e = succ[e]) { 
    dfs(to[e]); 
  } 
  postorder[p++] = u; 
} 

void dfs_r(int u, int mark) { 
  if (seen_r[u]) return; 
  seen_r[u] = true; 
  scc[u] = mark; 
  for (int e = start_r[u]; ~e; e = succ_r[e]) { 
    dfs_r(to_r[e], mark); 
  } 
} 

int compute_sccs() {
  memset(seen, 0, sizeof seen);
  memset(seen_r, 0, sizeof seen_r);
  p = 0;
  int sccs = 0; 
  for (int i = 1; i <= n; i++) { 
    if (!seen[i]) { 
      dfs(i); 
    } 
  } 
  for (int i = p - 1; i >= 0; i--) { 
    int u = postorder[i]; 
    if (!seen_r[u]) { 
      dfs_r(u, sccs++); 
    } 
  } 
  return sccs; 
} 

void init() {
  E = 0;
  E_r = 0;
  memset(start, -1, sizeof start);
  memset(start_r, -1, sizeof start_r);
}

int main() {
  while(scanf("%d %d", &n, &m) != EOF) {
    init();
    for (int i=0; i<m; i++) {
      int i1, i2;
      char ch;
      scanf(" %c", &ch);
      bool flag1 = (ch == '+');
      scanf("%d", &i1);
      i1--;
      scanf(" %c", &ch);
      bool flag2 = (ch == '+');
      scanf("%d", &i2);
      i2--;
      if (flag1 && flag2) {
        //add_edge(inv(i1), i2);
        add_edge(i1, inv(i2));
        add_edge(i2, inv(i1));
      } else if (!flag1 && !flag2) {
        //add_edge(i1, inv(i2));
        add_edge(inv(i1), i2);
        add_edge(inv(i2), i1);
      } else if (flag1 && !flag2) {
        //add_edge(inv(i1), inv(i2));
        add_edge(i1, i2);
        add_edge(inv(i2), inv(i1));
      } else {
        //add_edge(i1, i2);
        add_edge(inv(i1), inv(i2));
        add_edge(i2, i1);
      }
    }
    compute_sccs();
    bool good = true;
    for (int i=0; i<n; i++) {
      if (scc[i] == scc[inv(i)]) good = false;
    }
    printf("%d\n", (good) ? 1 : 0);
  }

  return 0;
}
