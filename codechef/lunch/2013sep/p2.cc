#include <bits/stdc++.h>
#include <climits>
using namespace std;
#define s(x) scanf("%d", &x)

#define MAX_INT 3e9l
#define SIZE 2010
typedef long long ll;
int main() {
    int t, n, i, j, k;
    int a[SIZE];
    s(t);
    while (t--) {
        s(n);
        for (i=0; i<n; i++) {
            s(a[i]);
        }
        int ans = 0;
        for (i=0; i<n-2; i++)
            for (j=i+1; j<n-1; j++)
                for (k=j+1; k<n; k++) 
                    ans = max(ans, a[i]^a[j]^a[k]);
        printf("%d\n", ans);
    }
    return 0;
}
