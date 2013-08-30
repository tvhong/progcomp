#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define sl(n) scanf("%lld", &n)
#define s(n) scanf("%d", &n)

long long int N,W,x,sum,sqsum,i,tmp1,tmp2,cnt;

int check() {
    long long tmp = sum - tmp1;
    if (tmp % W == 0) {
        x = tmp / W;
        tmp = W*x*x + 2*tmp1*x + tmp2;
        /*
        printf("x=%lld ", x);
        printf("tmp=%lld ", tmp);
        printf("sqsum=%lld\n", sqsum);
        */
        if (tmp == sqsum) return 1;
    }
    return 0;
}

int main() {
    sl(N); sl(W);
    int a[N];
    //printf("%d ", W);
    tmp1 = (W*(W-1))/2;
    tmp2 = (W*(W-1)*(2*W-1))/6;
    //printf("%lld ", tmp1);
    //printf("%lld ", tmp2);
    sum = 0;
    sqsum = 0;
    cnt = 0;
    for (i=0;i<W;i++){
        s(a[i]);
        sum += a[i];
        sqsum += a[i]*a[i];
    }
    if (check()) cnt++;
    for(;i<N;i++) {
    //printf("%lld\n", i);
        s(a[i]);
        sum += a[i] - a[i-W];
        sqsum += a[i]*(long long)a[i] - a[i-W]*(long long)a[i-W];
        if (check()) cnt++;
    }
    printf("%lld\n", cnt);
    return 0;
}
