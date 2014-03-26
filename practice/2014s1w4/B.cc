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
int a[N];
int main() {
  int n, m, x, y;
  while (scanf("%d %d", &n, &m) != EOF) {
    e.clear();
    for (int i=0;i <n;i++) {
      scanf("%d", &a[i]);
    }
    for (int i=0;i <m;i++) {
      scanf("%d %d", &x, &y);
      if (x > y) swap(x, y);
      e.push_back(mp(x, y));
    }
    sort(e.begin(), e.end());
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
