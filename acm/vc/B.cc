//#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#define SIZE 20

int main() {
    int n, b, i, j, a[SIZE], s;
    int max = 0;
    int ans = (int) 1e6;

    scanf("%d %d", &n, &b);
    for (i = 0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    max = 1<<n+1;

    //for (i=0; i<n; i++) printf("a[%d]=%d\n", i, a[i]);

    //printf("ans=%d, max=%d\n", ans, max);
    for (i=1; i<max; i++) {
        s = 0;
        for (j=0; j<n; j++) {
            if (i & 1<<j) s += a[j];
        }
        //printf("i=%d, s=%d\n", i, s);
        int tmp = s - b;
        if (tmp>=0 && tmp<ans) ans = tmp;
    }

    printf("%d\n", ans);
    return 0;
}
