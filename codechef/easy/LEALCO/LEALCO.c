#include <stdio.h>
#define s(n) scanf("%d", &n)

int i,j,m,n,k,t,changes,min;
int R[17], newR[17];
int isBad() {
    int i, j, maxR, cnt;
    for (i=0;i<=n-k;i++) {
        maxR = 0;
        cnt = 0;
        for (j=0;j<k;j++) {
            if (newR[i+j] > maxR) {
                maxR = newR[i+j];
                cnt = 0;
            }
            if (newR[i+j] == maxR) cnt++;
        }
        if (cnt >= m) return 1;
    }
    return 0;
}
int main() {
    s(t);
    while(t--) {
        s(n); s(k); s(m);
        for (i=0;i<n;i++) s(R[i]);
        min = n+1;
        for (i=0;i<(1<<n);i++) {
            changes = 0;
            for (j=0;j<n;j++) {
                if (i & 1<<j) {
                    newR[j] = R[j]+1;
                    changes++;
                } else {
                    newR[j] = R[j];
                }
            }
            if (!isBad() && changes < min) min = changes;
        }
        min == n+1 ? printf("-1\n") : printf("%d\n", min);
    }
    return 0;
}
