#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 3000 + 5;

int day[N], good, good2, ans, n, v;

void take(int& fruit, int& v) {
  if (v >= fruit) {
    ans += fruit;
    v -= fruit;
    fruit = 0;
  } else {
    ans += v;
    fruit -= v;
    v = 0;
  }
}
int main() {
  scanf("%d %d", &n, &v);
  for (int i=0; i<n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    day[x] += y;
  }
  int w;
  for (int i=1; i<=N; i++) {
    w = v;
    if (day[i-1] && w) {
      take(day[i-1], w);
      //printf("day[i-1] = %d, w=%d\n", day[i-1], w);
    }
    if (day[i] && w) {
      take(day[i], w);
      //printf("day[i] = %d\n", day[i-1]);
    }
    //printf("%d w=%d, ans=%d\n", i, w, ans);
  }
  printf("%d\n", ans);
  return 0;
}
