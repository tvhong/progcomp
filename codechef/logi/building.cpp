#include <bits/stdc++.h>

#define s(x) scanf("%lld", &x);
typedef long long ll;
int main() {
    ll T, N;
    s(T);
    while (T--) {
        s(N);
        printf("%lld\n", N-(N/2+1)+1);
    }
    return 0;
}
