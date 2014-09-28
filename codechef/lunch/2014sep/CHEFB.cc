#include <bits/stdc++.h>

using namespace std;
int T, n, nprimes, ans;

const int N = 1e6;
bool notprime[N+5];
int primes[N+5];
int gpower[N+5];

void fact(int x) {
    for (int i=0; i<nprimes && primes[i]*primes[i] <= x && x > 1; i++) {
        int multiple = 0;
        while (x % primes[i] == 0) {
            x /= primes[i];
            multiple++;
        }
        if (multiple > gpower[i]) {
            ans = ans - gpower[i] + multiple;
            gpower[i] = multiple;
        }
    }
    if (x > 1) {
        int* it = lower_bound(primes, primes + nprimes, x);
        int i = it - primes;
        if (gpower[i] < 1) {
            ans = ans + 1;
            gpower[i] = 1;
        }
    }
}

int main() {
    for (int i=2; i<=N; i++) {
        if (notprime[i]) continue;
        primes[nprimes++] = i;
        for (int j=i; j<=N; j+=i) {
            notprime[j] = true;
        }
    }


    scanf("%d", &T);
    while (T--) {
        ans = 0;
        memset(gpower, 0, sizeof(gpower));
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            int x;
            scanf("%d", &x);
            fact(x);
        }
        printf("%d\n", ans);
    }
    return 0;
}
