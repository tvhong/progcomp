#include <cstdio>

int main() {
    int k, n, tt, i, t;
    char z;
    scanf("%d", &k);
    scanf("%d", &n);
    tt = 0;
    for (i=0; i<n; i++) {
        scanf("%d %c", &t, &z);
        tt += t;
        if (tt > 210)
            break;
        //if (t > 
        if (z == 'T')
            k++;
    }
    printf("%d\n", k);
    return 0;
}
