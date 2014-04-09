#include <cstdio>
#include <cmath>

using namespace std;

int n, x, y;

int parent(int n) {
  return n/2;
}

int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%d %d", &x, &y);
    int lx = log2(x);
    int ly = log2(y);
    int cnt = 0;
    while (lx > ly) cnt++, x = parent(x), lx--;
    while (ly > lx) cnt++, y = parent(y), ly--;
    while (x != y) {
      x = parent(x);
      y = parent(y);
      cnt+=2;
    }
    printf("%d\n", cnt);
  }
  return 0;
}
