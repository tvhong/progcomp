//#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#define SIZE 20010

int cmp (const void * pa, const void *pb) {
    int a = *(int*) pa, b = *(int*)pb;
    return b - a;
}

int main() {
    int n, b, i, a[SIZE], s;

    scanf("%d %d", &n, &b);
    for (i = 0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp);
    i = 0;
    s = 0;
    while(s < b) {
        //printf("%d\n", a[i]);
        s += a[i++];
    }
    printf("%d\n", i);
    return 0;
}
