#include <cstdio>
using namespace std;

#define sc(N) scanf("%d", &N)
#define SIZE 500

int isprime(int n) {
    int i;
    for (i=2; i*i <= n; i++) 
        if (n % i == 0) return 0;
    return 1;
}

int min(int x, int y) {
    return (x < y)? x:y;
}

int main() {
    int t, n, m, res;
    int i,j;
    char a[SIZE][SIZE];
    int l[SIZE][SIZE], r[SIZE][SIZE], u[SIZE][SIZE], b[SIZE][SIZE];
    int primes[SIZE];
    int nPrimes = 0;

    for (i=2; i <= SIZE; i++)
        if (isprime(i))
            primes[nPrimes++] = i;

    /*
    for (i=0; i < nPrimes; i++)
        printf("%d ", primes[i]);
    printf("\n");
    */
    
    sc(t);
    while (t--) {
        scanf("%d %d", &n, &m);
        scanf("\n", NULL);
        for (i=0; i < n; i++) {
            for (j=0; j < m; j++) {
                scanf("%c", &a[i][j]);
                //printf("%c", a[i][j]);
                l[i][j] = 0; r[i][j] = 0; u[i][j] = 0; b[i][j] = 0;
            }
            scanf("\n", NULL);
        }
        for (i=1; i < n; i++) 
            for (j=1; j < m; j++) {
                if (a[i][j]=='#') continue;
                l[i][j] = (a[i][j-1]=='^') ? l[i][j-1]+1 : 0;
                u[i][j] = (a[i-1][j]=='^') ? u[i-1][j]+1 : 0;
            }

        //printf("n=%d\n", n);
        for (i=n-2; i >= 0; i--) 
            for (j=m-2; j >= 0; j--) {
                if (a[i][j]=='#') continue;
                r[i][j] = (a[i][j+1]=='^') ? r[i][j+1]+1 : 0;
                b[i][j] = (a[i+1][j]=='^') ? b[i+1][j]+1 : 0;
                //printf("r[%d][%d]=%d ", i, j, r[i][j]);
                //printf("b[%d][%d]=%d\n",i, j, b[i][j]);
            }

        res=0;
        for (i=0; i < n; i++) 
            for (j=0; j < m; j++) {
                int minVal = min(l[i][j], r[i][j]);
                minVal = min(minVal, u[i][j]);
                minVal = min(minVal, b[i][j]);
                int k;
                for (k = 0; k < nPrimes; k++)
                    if (minVal < primes[k]) break;
                if (k > 0) res += k;
            }

        //printf("%d %d %d %d\n", l[2][3], r[2][3], u[2][3], b[2][3]);
        printf("%d\n", res);
    }
    return 0;
}
