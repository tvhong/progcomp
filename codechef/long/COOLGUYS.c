#include <stdio.h>
#include <math.h>

#define s(n) scanf("%lld", &n)
#define swap(a, b) {long long tmp = a; a = b; b = tmp;}
long long gcd(long long a, long long b) {
    if (a == 0) return b;
    if (b == 0) return a;
    int d = 1;
    while (a != b) {
        if ((a&1) && (b&1)) {
            if (b > a) swap(a, b);
            b = gcd(b, (a-b)/2);
            break;
        } else if (!(a&1) && !(b&1)) {
            d <<= 1;
            a >>= 1;
            b >>= 1;
        } else if (!(a&1)) {
            a >>= 1;
        } else {
            b >>= 1;
            //printf("%lld\n", b);
        }
    }
    return b * d;
}

int main() {
    long long T, N;
    int i;
    long long res;
    s(T);
    while (T--) {
        s(N);
        res = 0;
        int sqrt_n = sqrt(N);
        for (i = 1; i <= sqrt_n; i++) {
            res += N / i;
        }
        //printf ("%d\n", res);
        for (i = 1; i <= sqrt_n; i++) {
            if (N/i == i) continue;
            res += (N/i - N/(i+1))*i;
            //printf ("%d\n", i);
        }
        //printf ("%d\n", res);
        long long g = gcd(res, N*N);
        //long long g = 1;
        printf("%lld/%lld\n", res/g, N*N/g);
    }
    return 0;
}
