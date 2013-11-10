#include <cstdio>
#include <cmath>

#define s(x) scanf("%lld", &x)
#define PRIME 1000000007
#define SIZE 32
#define MAX 10000000000
typedef long long LL;

using namespace std;

LL m;
char nBin[SIZE];
LL fast_pow() {
    LL base = 2;
    LL res = 1;
    for (LL i=0; i<m; i++) {
        //printf("b=%lld\n", base);
        if (nBin[i]) res = (res*base) % PRIME;
        LL tmp = base;
        for (LL j=1; j<10; j++) 
            tmp = (tmp*base) % PRIME;
        base = tmp;
    }
    return res;
}

int main() {
    LL t, n;
    s(t);
    while (t--) {
        s(n);
        m = 0;
        while (n>0) {
            if (n&1) nBin[m] = 1;
            else nBin[m] = 0;
            m++;
            n>>=1;
        }
        /*
        for (LL i=m-1; i>=0; i--) 
            printf("%d", nBin[i]);
        printf("\n");
        */
        LL ans = fast_pow();
        ans = (ans*ans) % PRIME;
        printf("%lld\n", ans);
    }
    return 0;
}
