#include <bits/stdc++.h>

using namespace std;
const int N = 1e5+5;
int T, n, a[N];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a, a+n);
        long long ans = 0;
        for (int i=n-1; i>=0; i-=2) {
            ans += a[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
