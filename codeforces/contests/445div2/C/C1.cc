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
int n, m;
Vertex vers[N];

int main() {
  scanf("%d %d", &n, &m);
  for (int i=0; i<n; i++) {
    scanf("%d", &vers[i].v);
    vers[i].e = 0;
  }
  double maxden = 0;
  for (int i=0; i<m; i++) {
    int x, y, c;
    scanf("%d %d %d", &x, &y, &c);
    x--, y--;
    double den = 1.0*(vers[x].v + vers[y].v) / c;
    maxden = max(maxden, den);
  }

  printf("%.9f\n", maxden);
  return 0;
}
