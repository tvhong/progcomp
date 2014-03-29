#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 50;
int flags[N];

int main() {
  int n;
  while (scanf("%d", &n), n) {
    memset(flags, 0, sizeof flags);
    for (int i=0; i<n; i++) {
      for (int j=0; j<6; j++) {
        int x;
        scanf("%d", &x);
        flags[x] = 1;
      }
    }
    bool good = true;
    for (int i=1; i<=49; i++) {
      if (flags[i] == false) good = false;
    }
    printf("%s\n", (good) ? "Yes" : "No");
  }
  return 0;
}
