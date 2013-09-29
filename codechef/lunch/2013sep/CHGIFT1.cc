#include <bits/stdc++.h>
using namespace std;
#define s(x) scanf("%lld", &x)
#define ADD 0
#define SUB 1
#define MUL 2
#define MAX_INT 4e9l
#define MIN_INT -4e9l
#define SIZE 100010

typedef long long ll;

ll cal(ll a, ll b, ll op) {
    if (op == ADD) return a+b;
    if (op == SUB) return a-b;
    return a*b;
}

ll min(ll a, ll b) {
    return (a<b)?a:b;
}

ll max(ll a, ll b) {
    return (a>b)?a:b;
}

int main() {
    ll t, n, i, j;
    ll a[SIZE], mi[SIZE], ma[SIZE];
    s(t);
    while (t--) {
        s(n);
        s(a[0]);
        mi[0] = a[0];
        ma[0] = a[0];
        for (i=1; i<n; i++) {
            s(a[i]);
            mi[i] = MAX_INT;
            ma[i] = MIN_INT;
            //printf("mi=%lld\n", mi[i]);
            //printf("ma=%lld\n", ma[i]);
            for (j=0; j<3; j++) {
                ll tmp1 = cal(mi[i-1], a[i], j);
                ll tmp2 = cal(ma[i-1], a[i], j);
                if (tmp1 > tmp2) swap(tmp1, tmp2);
                //printf("i=%lld j=%lld tmp1=%lld tmp2=%lld\n", i, j, tmp1, tmp2);
                mi[i] = min(mi[i], tmp1);
                ma[i] = max(ma[i], tmp2);
            }
        }
        /*
        printf("mi[i]=");
        for(i=0;i<n;i++) printf("%lld ", mi[i]);
        printf("\n");
        printf("ma[i]=");
        for(i=0;i<n;i++) printf("%lld ", ma[i]);
        printf("\n");
        */
        printf ("%lld\n", mi[n-1]);
    }
    return 0;
}
