#include <stdio.h>
#include <math.h>

int main() {
    int primes[10001];
    int nprime = 1;
    primes[0] = 2;
    int t,n,i,j;
    for (i = 3;i<=10001;i+=2) {
        int sqrti = sqrt(i);
        //printf("sqrti = %d", sqrti);
        for (j=2;j<=sqrti;j++) {
            if (i % j == 0) break;
        }
        if (j == sqrti+1) {
            primes[nprime++] = i;
        }
    }

    //printf("%d\n", nprime);
    int ans[10001] = {0};
    for (i=0; i<nprime; i++) {
        int sum = primes[i] + 2*primes[i];
        if (sum < 10001) ans[sum]++;
        for (j=i+1; j<nprime; j++) {
            sum = primes[i] + 2*primes[j];
            if (sum < 10001) ans[sum]++;
            sum = primes[j] + 2*primes[i];
            if (sum < 10001) ans[sum]++;
        }
    }
    //printf("%d\n", ans[2]);

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }
    return 0;

}
