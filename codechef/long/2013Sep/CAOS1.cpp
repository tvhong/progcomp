#include <cstdio>
using namespace std;

#define sc(N) scanf("%d", &N)
int isprime(int n) {
    int i;
    for (i=2; i*i <= n; i++) 
        if (n % i == 0) return 0;
    return 1;
}


int main() {
    int t, n, m, res;
    int i,j;
    char a[50][50];
    int l[50][50], r[50][50], u[50][50], b[50][50];
    char rub;
    sc(t);
    while (t--) {
        scanf("%d %d", &n, &m);
        scanf("%c", &rub);
        //printf("%d %d\n", n, m);
        for (i=0; i < n; i++) {
            for (j=0; j < m; j++) {
                scanf("%c", &a[i][j]);
                //printf("%c", a[i][j]);
                l[i][j] = 0; r[i][j] = 0; u[i][j] = 0; b[i][j] = 0;
            }
            scanf("%c", &rub);
        }
        res=0;
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
        for (i=0; i < n; i++) 
            for (j=0; j < m; j++)
                if (l[i][j] >= 2 && r[i][j] >= 2 && u[i][j] >= 2 && b[i][j] >= 2) res++;

        //printf("%d %d %d %d\n", l[2][3], r[2][3], u[2][3], b[2][3]);
        printf("%d\n", res);
    }


    return 0;
}
