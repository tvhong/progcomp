#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define pr(n) printf("%d ", n)
#define prln() printf("\n")

#define MOD 1000000007

//only works if there's exactly 1 space/newline after the number
int s() {
    int inp=0;
    char c=getchar_unlocked();
    while (c>='0'&&c<='9') {
        inp = inp*10+c-'0';
        c=getchar_unlocked();
    }
    return inp;
}

int fastPow(int a, int n) {
    int p = 1;
    while(n>0) {
        if (n&1) p=(long long) p*a%MOD;
        a = (long long) a*a % MOD;
        n >>= 1;
    }
    return p;
}
int main() {
    int t,n;
    //t = s();
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        //n = s();
        //pr(n);
        //pr(n&1==1);
        //pr(n>>1);
        //pr(fastPow(3,n));
        int ans = fastPow(3, n) + 3*(n&1?-1:1);
        if (ans < 0) ans += MOD;
        else if (ans>=MOD) ans -= MOD;
        printf("%d\n", ans);
    }
    //prln();
    return 0;
}
