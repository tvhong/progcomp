/* Solution to "Reduced ID Numbers" from NWERC 05
 * Author: Per Austrin */
#include <cstdio>
main(void) { int i, j, k, n, m, *v = 314+new int[100000];
  for (scanf("%d", &n); n-- && scanf("%d", &m); printf("%d\n", k))
    for (*v=i=(k=1)-1; i++<m && scanf("%d", v-i);)
      for (j=i; j<=i && (v[v[-j]%k]-k?v[v[-j]%k]=k:*(v+k++)=(j=-1)++); ++j);
}
