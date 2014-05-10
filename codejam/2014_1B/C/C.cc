#include <bits/stdc++.h>

using namespace std;

int const N = 10;
int const M = N*N;
typedef struct {
  string azip;
  int n;
  int cur;
} State;


int E, last[2][N], to[2][M], next[2][M];
void add_edge(int id, int u, int v) {
  to[id][E] = v;
  next[id][E] = last[id][u];
  last[id][u] = E++;
}

int T, n, m;
string zip[N];

void solve() {
  for (int i=1; i<=n; i++) {
    set<State> visited;
    State s;
    s.azip = zip[i], s.n = 1, s.cur = i;
    queue<State> q;
    for (q.push(s); !q.empty(); q.pop()) {
      State ss = q.top();
      visited.insert(ss);
      for (int e = last[0][ss.cur]; ~e; e = next[0][e]) {
        State ns = ss;
        if (ns.visited[
        

      }
    }
  }
}

void init() {
}
int main() {
  scanf("%d", &T);
  for (int t= 1; t<=T; t++) {
    printf("Case #%d: ", t);
    init();
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++) {
      cin >> zip[i];
    }
    for (int i=0; i<m; i++) {
      int u, v;
      cin >>u >> v;
      add_edge(0, u, v);
      add_edge(1, v, u);
    }
    solve();
  }

  return 0;
}
