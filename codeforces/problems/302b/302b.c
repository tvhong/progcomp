#include <stdio.h>

int bsearch(int val, int* a, int low, int n) {
    //printf("%d\n", n);
    int lo = low-1, hi = n;
    while (hi-lo > 1) {
        int mid = (lo+hi)/2;
        if (a[mid] < val) lo = mid;
        else hi = mid;
    }
    return hi;
}

int main() {
    //read in n
    //find the first i that's greater than v
    int SIZE = 100001;
    int i,n,m;
    int c, t , v[SIZE], tt[SIZE];//tt: finish at
    scanf("%d %d", &n, &m);
    int sum = 0;
    for (i=1; i<=n; i++) {
        scanf("%d %d", &c, &t);
        sum += c * t;
        tt[i] = sum;
        //printf("%d\n", tt[i]);
    }
    for (i=1; i<=m; i++) {
        scanf("%d", &v[i]);
    }

    int last = 1;
    for (i=1; i<=m; i++) {
        //last = bsearch(v[i], tt, last, n);
        last = bsearch(v[i], tt, 1, n);
        printf("%d\n", last);
    }
    return 0;
}
