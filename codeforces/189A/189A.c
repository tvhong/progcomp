#include <stdio.h>

#define MAX_N 8010
#define NO_VAL -2

int r[MAX_N+1];
int n,a,b,c;

int max(int x, int y) {
    if (x > y) return x;
    return y;
}

int main() {
    int i;
    scanf("%d %d %d %d", &n, &a, &b, &c);
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
//    printf("%d\n", c);
    for (i=0;i<=MAX_N;i++) {
        r[i] = NO_VAL;
    }
    r[a] = 1;
    r[b] = 1;
    r[c] = 1;
    //c = 2;
    for (i=min;i<=n;i++) {
        //printf("c = %d\n", c);
        if (r[i] != NO_VAL) {
            r[i+a] = max(r[i+a], r[i]+1);
            r[i+b] = max(r[i+b], r[i]+1);
            r[i+c] = max(r[i+c], r[i]+1);
        }
        //if (i == 5) printf("SIT%d, %d, %d\n", r[i], c, r[i+c]);
    }
    printf("%d\n", r[n]);

/*
    for (i = 0; i<=n; i++) {
        printf("r[%d]=%d\n", i,r[i]);
    }
*/

    return 0;
}
