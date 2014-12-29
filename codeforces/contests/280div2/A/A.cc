#include <cstdio>

int main() {
    int n, i, blk = 0;
    scanf("%d", &n);
    for (i = 1; n > 0; i++) {
        blk += i;
        if (n < blk) break;
        n -= blk;
    }
    printf("%d\n", i-1);
    return 0;
}
