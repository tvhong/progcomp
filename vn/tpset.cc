#include <cstdio>
#include <cmath>

typedef long long LL;
using namespace std;

LL cal(LL n) {
    if (n == 0) return 0;
    LL m = log2(n);
    //printf("n=%lld, m=%lld\n", n, m);
    LL pow3m = pow(3, m);
    LL pow2m = (LL)1<<m;
    return pow3m + cal(n - pow2m);
}

int main() {
    LL n;
    while (scanf("%lld", &n) != EOF) {
        printf("%lld\n", cal(n));
    }
}
