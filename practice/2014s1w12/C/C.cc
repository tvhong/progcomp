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
bool iscycle;
map<int, set<int> > edges;
map<int, int> seen;

int DFS(int from, int u) {
  //printf("visiting %d\n", u);
  if (seen[u]) {
    iscycle = true;
    return 0;
  }
  seen[u] = 1;
  int res = 1;
  for (set<int>::iterator it = edges[u].begin(); it != edges[u].end(); ++it) {
    if (*it == from) continue;
    res += DFS(u, *it);
  }
  return res;
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
      if (u != v) {
        edges[u].insert(v);
        edges[v].insert(u);
      }
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
        iscycle = false;
        int l = DFS(-1, it->first);
        //printf("start from %d, iscycle= %d, dfs=%d\n", it->first, iscycle, l);
        if (iscycle && l != n) {
          good = false;
          break;
        }
      }
    }
    printf("%c\n", (good) ? 'Y' : 'N');
  }

  return 0;
}
