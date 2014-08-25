#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5;
int n;
long long dp[N+5], cnt[N+5];

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    long long ans = 0;
    dp[0] = 0;
    dp[1] = cnt[1];
    ans = dp[1];
    for(int i=2; i<=N; i++) {
        dp[i] = max(cnt[i]*i+dp[i-2], dp[i-1]);
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
