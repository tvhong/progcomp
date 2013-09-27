#include <stdio.h>

int main() {
    int n, p, c;
    scanf("%d", &n);
    while (n!= 0) {
        n <<= 1;
        p = c = n / 7;
        n = n - p*7;
        if (n >= 5) {
            c++;
            n -= 5;
        } else if (n>=2) {
            p++;
            n -= 2;
        }
        printf("%.1f %.1f %.1f %.1f\n", n/2.0, p/2.0, p/2.0, c/2.0);
        scanf("%d", &n);
    }
    return 0;
}
