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
int p[N];

const int N = 10000;
int root(int i) {
  return p[i] == i ? i : p[i] = root(p[i]);
}
int main() {
  int n, m, x, y;
  int a[N];
  while (scanf("%d %d", &n, &m) != EOF) {
    for (int i=0;i <n;i++) {
      scanf("%d", &a[i]);
      p[i] = i;
    }
    for (int i=0;i <m;i++) {
      scanf("%d %d", &x, &y);
      if (x > y) 
    }
    for (int i=e.size()-1; i>=0; i--) {
      x = e[i].x;
      y = e[i].y;
      a[x] += a[y];
      a[y] = 0;
      //cout << x << " " << y << endl;
    }
    bool good = true;
    for (int i=0; i<n; i++) {
      if (a[i] != 0) good = false;
      //cout << a[i] << " ";
    }
    //cout << endl;
    printf("%s\n", (good) ?  "POSSIBLE" : "IMPOSSIBLE");
  }
  return 0;
}
