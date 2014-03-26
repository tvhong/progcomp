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

int main() {
  int e, f, c;
  while (scanf("%d %d %d", &e, &f, &c) != EOF) {
    int n = e+f;
    int cnt = 0;
    while (n >= c) {
      n -= c;
      cnt++;
      n++;
    }
    printf("%d\n", cnt);
  }
  return 0;
}
