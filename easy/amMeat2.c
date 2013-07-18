#include <stdio.h>

int n,k,t;
int main() {
    for (scanf("%d", &t); t--; ) {
        scanf("%d %d", &n, &k);
        if (n == 1 && k == 1) {
            printf("1\n");
        } else if (k > n/2) {
            printf("-1\n");
        } else {
            while (k > 1) {
                printf("%d ", k*2);
                k--;
            }
            printf("%d\n", k*2);
        }
        //printf("SHIT\n");
    }
    return 0;
}
