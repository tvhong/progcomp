#include <stdio.h>
#include <math.h>

#define s(n) scanf("%d", &n)

int t,n,m,j,yes,power,sum;
unsigned int i;
int a[20];

int bt(int k, int val) {
    if (val == 0) return 1;
    if (k < 0) return 0;
    if (val < 0) return 0;
    return bt(k-1, val) || bt(k-1, val-a[k]);
}
int main() {
    for (s(t); t--;) {
        s(n);
        s(m);
        for(i=0;i<n;i++) {
            s(a[i]);
        }
        bt(n-1, m) ? printf("Yes\n") : printf("No\n");
    }
    return 0;
}

