#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;
#define x first
#define y second
#define mp make_pair

const int N = 55;
int n, m, p[N];
long long ans;

int root(int x) {
  return x == p[x] ? x : (p[x] = root(p[x]));
}

void merge(int x, int y) {
  int p1 = root(x);
  int p2 = root(y);
  if (p1 != p2) {
    ans <<= 1;
    if (rand() & 1) {
      p[p1] = p2;
    } else {
      p[p2] = p1;
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i=0; i<n; i++)
    p[i] = i;
  ans = 1;
  for (int i=0; i<m; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    x--, y--;
    merge(x, y);
  }
  cout << ans << endl;
  return 0;
}
