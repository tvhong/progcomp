#include <stdio.h>

typedef long long LL;
LL getVal(int* a, int i, int k, int n) {
    if (i+k >= n) return 0;
    return 1 + a[i] + a[i+k] + a[i]*a[i+k];
}

int main() {
    int i,k,n;
    int a[1000001]; //store number of 0's precede the ith 1's
    scanf("%d", &k);
    n = 0;
    char ch = getchar(); //skip \n
    do {
        ch = getchar();
        int cnt = 0;
        while (ch == '0') {
            //printf("shit\n");
            cnt++;
            ch = getchar();
        }
        if (ch != EOF) {
            a[n++] = cnt;
        }
    } while (ch != EOF);
    /*
    for (i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
    */
    LL ans = 0;
    if (k == 0) {
        for (i=0; i<n;i++) {
            ans += a[i]*(a[i]+1)/2;
        }
    } else {
        for (i=0; i+k<n;i++) {
            ans += getVal(a, i, k, n);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
