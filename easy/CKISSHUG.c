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
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        //int pow1 = n&1 ? (n+1)>>1 : ((n+1)>>1) + 1;
        //int pow2 = (n+1)>>1;
        //pr(pow1);
        //pr(pow2);
        long long floor = fastPow(2, (n+1)>>1);
        long long ans = floor - 2;
        if (n&1) ans += floor;
        else ans += floor<<1;
        //int ans = fastPow(2, pow1) + fastPow(2, pow2) - 2;
        if (ans < 0) ans += MOD;
        else if (ans>=MOD) ans %= MOD;
        printf("%lld\n", ans);
    }
    return 0;
}
