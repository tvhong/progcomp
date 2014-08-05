#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 105;
const int P = 17;
const int MAX_INT = 30*100;
int n, a[N], dp[N][1<<P], fact[N], via[N][1<<P], res[N];
int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};

void print_result() {
    int mn = MAX_INT;
    int mask = 0;
    for (int s=1; s<(1<<P); s++) {
        if (dp[n-1][s] < mn) {
            mn = dp[n-1][s];
            mask = s;
        }
    }
    for (int i = n-1; i>=0; i--) {
        //printf("via[%d][0x%x]=%d\n", i, mask, via[i][mask]);
        res[i] = via[i][mask];
        //printf("pushed %d\n", via[i][mask]);
        mask = mask & (~fact[via[i][mask]]);
        //printf("newmask = 0x%x\n", mask);
    }
    for (int i = 0; i<n; i++) {
        printf("%d%c", res[i], i!=n-1 ? ' ' : '\n');
    }
}
int main() {
    for (int i=1; i<60; i++) {
        for (int j=0; j<P; j++)
            if (i % primes[j] == 0) fact[i] |= (1<<j);
    }
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i=0; i<n; i++)
        for (int j = 0; j < (1<<P); j++)
            dp[i][j] = MAX_INT;

    for (int i=0; i<n; i++) {
        for (int k=1; k<60; k++) {
            int x = (~fact[k]) & ((1<<P)-1);
            for (int s = x; s!=0; s = (s-1) & x) {
                int prev = i ? dp[i-1][s] : 0;
                if (prev + abs(a[i]-k) < dp[i][s | fact[k]]) {
                    dp[i][s|fact[k]] = prev + abs(a[i]-k);
                    via[i][s|fact[k]] = k;
                }
            }
        }
    }
    print_result();
    return 0;
}
