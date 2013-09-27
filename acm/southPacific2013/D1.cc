#include <bits/stdc++.h>

typedef long long ll;
ll sum(ll n) {
    return n*(n+1)/2;
}

inline ll getnum() {ll a; scanf("%lld", &a); return a;}
int main() {
    ll n;
    while ( (n=getnum()) ) {
        ll goal1 = sum(n) / 2;
        ll goal2 = goal1 + (sum(n) & 1);
        ll a=1, b=1;
        for (ll i=n; i>0; i--) {
            ll s = sum(i);
            if (s > goal2) continue;
            //printf("%lld %lld %lld\n", goal, s, i);
            if (((goal1 - s) % i) == 0) {
                a = 1 + (goal1 - s)/i;
                b = a + (i-1);
                break;
            }
            if (((goal2 - s) % i) == 0) {
                a = 1 + (goal2 - s)/i;
                b = a + (i-1);
                break;
            }
        }
        printf("%lld %lld\n", a, b);
    }
    return 0;
}
