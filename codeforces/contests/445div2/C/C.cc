#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <utility>

using namespace std;

#define x first
#define y second
#define mp make_pair

typedef pair<int, int> pt;
typedef struct {
  int v, e;
} Vertex;

const int N = 505;
const int MAX_DEN = 1e6 * 500;
const double EPS = 1e-9;
int n, m, adj[N][N], removed[N], p[N];
Vertex vers[N];

int root(int x) {
  return x == p[x] ? x : (p[x] = root(p[x]));
}


void join(int v1, int v2) {
  int p1 = root(v1), p2 = root(v2);
  //printf("joining %d %d, parents= %d %d\n", v1, v2, p1, p2);
  if (p1 != p2) {
    //if (rand() & 1) {
    if (p1 > p2) {
      swap(p1, p2);
    }
    removed[p2] = 1;
    p[p2] = p1; //merge p2 into p1
    vers[p1].v += vers[p2].v;
    vers[p1].e += adj[p1][p2];
    for (int i=0; i<n; i++) {
      if (i == p1 || i == p2 || removed[i]) continue;
      adj[p1][i] += adj[p2][i];
      adj[i][p1] += adj[i][p2];
    }
  }
}

void init() {
  for (int i=0; i<N; i++)
    p[i] = i;
  memset(removed, 0, sizeof removed);
}

int main() {
  init();
  scanf("%d %d", &n, &m);
  for (int i=0; i<n; i++) {
    scanf("%d", &vers[i].v);
    vers[i].e = 0;
  }
  for (int i=0; i<m; i++) {
    int x, y, c;
    scanf("%d %d %d", &x, &y, &c);
    x--, y--;
    adj[x][y] = c;
    adj[y][x] = c;
  }
  // merging
  double maxden = 0;
  for (int k=0; k<n; k++) {
    int mp1, mp2;
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
      if (removed[i] || removed[j]) continue;
      int p1 = root(i), p2 = root(j);
      double den = adj[p1][p2] ? 1.0*(vers[p1].v + vers[p2].v) / adj[p1][p2] : 0;
      //printf("p1.v=%d p2.v=%d, adj[%d][%d]=%d ", vers[p1].v, vers[p2].v, p1, p2, adj[p1][p2]);
      //printf("den=%f, maxden=%f\n", den, maxden);
      if (den > maxden) {
        maxden = den;
        mp1 = p1;
        mp2 = p2;
      }
    }
    if (fabs(maxden) < fabs(EPS)) break;
    join(mp1, mp2);
  }

  /*
  double maxden = 0;
  for (int i=0; i<n; i++) {
    double den = vers[i].e ? vers[i].v*1.0 / vers[i].e : 0;
    maxden = max(den, maxden);
  }
  */

  printf("%.9f\n", maxden);
  return 0;
}
