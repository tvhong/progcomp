#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define s(n) scanf("%d", &n)
#define pr(n) printf("%d", n)
#define prln() printf("\n")

int fastinput() {
    int inp=0;
    char c=getchar_unlocked();
    while (c>='0'&&c<='9') {
        inp = inp*10+c-'0';
        c=getchar_unlocked();
    }
    return inp;
}

int i,j,k,x,y,z,t,base;
int a[100][100][100];
int get(int i, int j, int k) {
    if (i < 0 || j < 0 || k < 0) return 0;
    return a[i][j][k];
}
int main() {
    s(t);
    while(t--) {
        s(x); s(y); s(z);
        for (i=0;i<x;i++) {
            for (j=0;j<y;j++) {
                for (k=0;k<z;k++) {
                    s(a[i][j][k]);
                    base = get(i-1,j,k) + get(i,j-1,k) + get(i,j,k-1)
                        - get(i-1,j-1,k) - get(i-1,j,k-1) - get(i,j-1,k-1)
                        + get(i-1,j-1,k-1);
                    //printf("%d ", base);
                    printf("%d ", a[i][j][k] - base);
                }
                prln();
            }
        }
    }
    return 0;
}
