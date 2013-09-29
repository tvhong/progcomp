#include <bits/stdc++.h>

#define s(x) scanf("%lld", &x)
typedef long long ll;
int main() {
    ll t, p, q;
    s(t);
    while (t--) {
        s(p);
        s(q);
        if (!(p&1) || !(q&1)) {
            printf("A\n");
        } else {
            printf("B\n");
        }
    }
    return 0;
}
