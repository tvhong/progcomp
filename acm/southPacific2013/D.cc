#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define sz(x) ((int)x.size())
#define x first
#define y second

typedef long long ll;

ll diff(ll a, ll b, ll n) {
    ll s1 = b*(b+1)/2 - a*(a-1)/2;
    ll s2 = n*(n+1)/2 - s1;
    return abs(s1-s2);
}

inline ll getint() {ll a; scanf("%lld", &a); return a;}

int main() {
    ll n;
    while ((n=getint())) {
        ll reta, retb, ret=n*(n+1)/2;
        ll a=1, b;
        for (b=1; b<=n; b++) {
            while (diff(a+1, b, n) < diff(a, b, n)) a++;
            if (diff(a, b, n) < ret) {
                reta = a;
                retb = b;
                ret = diff(a,b,n);
            }
        }
        printf("%lld %lld\n", reta, retb);
    }
}
