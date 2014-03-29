#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int n, t1, t2, t3;
  while (scanf("%d %d %d %d", &n, &t1, &t2, &t3), n) {
    int ans = 0;
    ans += 2*n + (n-1);
    if (t2>=t1)
      ans += n + (t2 - t1);
    else
      ans += n + (n-(t1-t2));
    if (t3>t2)
      ans += n -(t3-t2);
    else
      ans += t2 - t3;
    printf("%d\n", ans);
  }
  return 0;
}
