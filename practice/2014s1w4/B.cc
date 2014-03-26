#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>

#define x first
#define y second
#define mp make_pair
#define sz size()

using namespace std;

vector<pair<int, int> > e;

const int N = 10000;
int parent[N], a[N], val[N];
int root(int n) {
  return parent[n] == n ? n : parent[n] = root(parent[n]);
}

int join(int x, int y) {
  x = root(x);
  y = root(y);
  if (rand() & 1) {
    parent[x] = y;
  } else {
    parent[y] = x;
  }
}

int main() {
  int n, m, x, y;
  while (scanf("%d %d", &n, &m) != EOF) {
    for (int i=0;i <n;i++) {
      scanf("%d", &a[i]);
      parent[i] = i;
      val[i] = 0;
    }
    for (int i=0;i <m;i++) {
      scanf("%d %d", &x, &y);
      join(x, y);
    }
    bool good = true;
    for (int i = 0; i<n; i++) {
      int j = root(i);
      val[j] += a[i];
    }
    for (int i=0; i<n; i++) {
      if (val[i] != 0) good = false;
    }
    printf("%s\n", (good) ?  "POSSIBLE" : "IMPOSSIBLE");
  }
  return 0;
}
