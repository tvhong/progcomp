#include <bits/stdc++.h>

#define MAX 100010
#define MAX_INT 1000000
#define s(x) scanf("%lld", &x)

using namespace std;
typedef long long ll;
ll isPrime(ll n) {
    ll i, sqrtn = sqrt(n);
    for(i=2; i<=sqrtn; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    ll t,n,i,j,k,base,po;
    ll n_p=1;
    ll P[MAX], bw[MAX], bl[MAX];
    P[0]=2;
    for (i=3; i<=MAX; i+=2)
        if (isPrime(i))
            P[n_p++] = i;
    /*
    for (i=0;i<n_p; i++)
        printf("%d\n", P[i]);
    */
    for (i=0; i<MAX; i++) {
        bw[i] = MAX_INT;
        bl[i] = MAX_INT;
        //w[i] = 0;
    }
    //init best win
    bw[1]=1;
    //w[1]=1;
    for (j=0; j<n_p; j++) {
        base = P[j];
        for (k=1; ; k++) {
            po = pow(base, k);
            if (po > MAX) break;
            //printf("po=%lld\n", po);
            bw[po]=po;
            //w[po]=1;
        }
    }
    for(i=2;i<=MAX;i++)
        for (j=0; j<n_p; j++) {
            base = P[j];
            if (base > i) break;
            if (bw[i-1]==MAX_INT) bw[i] = min(bw[i], bl[i-1]);
            if (bl[i-1]==MAX_INT) bl[i] = min(bl[i], bw[i-1]);
            //printf("base=%lld\n", base);
            for (k=1; ; k++) {
                po = pow(base, k);
                if (po >= i) break;
                //printf("base=%lld k=%lld po=%lld\n", base, k, po);
                if (bw[i-po]==MAX_INT) bw[i] = min(bw[i], bl[i-po]);
                if (bl[i-po]==MAX_INT) bl[i] = min(bl[i], bw[i-po]);
            }
        }
    printf("HHAHAHA\n");
    s(t);
    while (t--) {
        s(n);
        /*
        printf("bw=");
        for(i=1;i<=n;i++) printf("%d ", bw[i]);
        printf("\nbl=");
        for(i=1;i<=n;i++) printf("%d ", bl[i]);
        printf("\n");
        */
        if (bw[n] < MAX_INT) 
            printf("Zack %lld\n", bw[n]);
        else 
            printf("Cody\n");
    }
    return 0;
}
