#include <bits/stdc++.h>

using namespace std;
typedef unsigned int uint;

uint A, B, K, T;
int main() {
  scanf("%d", &T);
  for (int t=1; t<=T; t++) {
    printf("Case #%d: ", t);
    scanf("%d %d %d", &A, &B, &K);
    //printf("%d %d %d\n", A, B, K);
    int cnt = 0;
    for (unsigned int i=0; i<A; i++) {
      for (unsigned int j=0; j<B; j++) {
        if ((i&j) < K) cnt++;
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}
