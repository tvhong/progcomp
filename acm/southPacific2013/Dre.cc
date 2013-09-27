#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
inline ll getn() {ll a; scanf("%lld", &a); return a;}

ll diff(ll a, ll b, ll n) {
    ll s1 = b*(b+1)/2 - a*(a-1)/2;
    ll s2 = n*(n+1)/2 - s1;
    return abs(s1 - s2);
}

int main() {
    ll n;
    while ( (n=getn()) ) {
        ll reta, retb, retd=n*(n+1)/2;
        ll b, a = 1;
        for (b=1; b<=n; b++) {
            while (diff(a+1,b,n) < diff(a, b, n)) a++;
            //printf("%lld %lld\n", a, b);
            if (diff(a,b,n) < retd) {
                retd = diff(a,b,n);
                reta = a;
                retb = b;
            }
        }
        printf("%lld %lld\n", reta, retb);
    }
    return 0;
}
