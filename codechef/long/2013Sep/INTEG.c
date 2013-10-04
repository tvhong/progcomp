#include <stdio.h>
#include <stdlib.h>

#define MAX 100000
#define s(n) scanf("%d", &n)

int cmp(const void * pa, const void * pb) {
    int* px = (int*) pa;
    int* py = (int*) pb;
    return *px - *py;
}

int main() {
    unsigned long long cost = 0;
    int N, X;
    int i, nNeg, eq0=0;
    int a[MAX];
    s(N);
    for (i = 0; i < N; i++) {
        s(a[i]);
    }
    s(X);

    qsort(a, N, sizeof(int), &cmp);
    nNeg = N;
    while (nNeg > 0) {
        while (nNeg > 0 && a[nNeg - 1] >= eq0) nNeg--;
        int diff = (nNeg) ? eq0-a[nNeg - 1] : 1;
        if (nNeg >= X) cost += (long long) X * diff;
        else cost += (long long) nNeg * diff;
        eq0 -= diff;
    }
    printf("%llu\n", cost);
    return 0;
}
