#include <cstdio>
#include <map>

#define s(x) scanf("%lld", &x)
#define PRIME 1000000007
typedef long long LL;

using namespace std;

map<LL, LL> cache;
LL cal(LL n) {
    if (n == 0) return 1;
    if (n == 1) return 2;
    return (cache[n]) ? cache[n] : (cache[n] = (cal(n/2) % PRIME * cal(n - n/2) % PRIME) % PRIME);
}

int main() {
    LL t, n;
    s(t);
    while (t--) {
        s(n);
        LL ans = (cal(n) - 1) % PRIME;
        printf("%lld\n", ans);
    }
    return 0;
}
