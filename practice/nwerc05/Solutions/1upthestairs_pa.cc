/* Solution to "Up the Stairs" from NWERC 05
 * Author: Per Austrin */
#include <cstdio>
#include <algorithm>
main() { int T, N, F, B, b, c[2323];
  for (scanf("%d", &T); scanf("%d%d%d", &N, &F, &B), B--, T--; 
       std::nth_element(c, c+B%N, c+N), printf("%d\n", B/N*2*F+F+c[B%N]))
    for (int i = 0; i < N && scanf("%d%d",c+i, &b); ++i) c[i] += 2*b*(F-c[i]);
}
