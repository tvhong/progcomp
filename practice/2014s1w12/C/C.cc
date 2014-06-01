#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>

#define x first
#define y second
#define mp make_pair
using namespace std;

int n, m, u, v;
map<int, set<int> > edges;
map<int, int> seen;

int DFS(int from, int u, int cnt) {
  printf("visiting %d, cnt = %d\n", u, cnt);
  if (seen[u]) return cnt;
  seen[u] = 1;
  for (set<int>::iterator it = edges[u].begin(); it != edges[u].end(); ++it) {
    if (*it == from) continue;
    return DFS(u, *it, cnt+1);
  }
  return 0;
}

void init() {
  edges.clear();
  seen.clear();
}
int main() {
  while (scanf("%d %d", &n, &m), !(n==0 && m==0)) {
    init();
    for (int i=0; i<m; i++) {
      scanf("%d %d", &u, &v);
      edges[u].insert(v);
      edges[v].insert(u);
    }
    typedef map<int, set<int> >::iterator it_type;
    bool good = true;
    for (it_type it = edges.begin(); it != edges.end(); ++it) {
      if (it->y.size() > 2) {
        good = false;
        break;
      }
    }
    if (!good) {
      printf("N\n");
      continue;
    }

    for (it_type it = edges.begin(); it != edges.end(); ++it) {
      if (!seen[it->first]) {
        int l = DFS(-1, it->first, 0);
        printf("start from %d, dfs=%d\n", it->first, l);
        if (l != 0 & l != n) {
          good = false;
          break;
        }
      }
    }
    printf("%c\n", (good) ? 'Y' : 'N');
  }

  return 0;
}
