#include <cstdio>

#define SIZE 110
using namespace std;
int main() {
    int n, k, t, i, a[SIZE];
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (i=0; i<n; i++) scanf("%d", &a[i]);
        scanf("%d", &k);
        k--;
        int ans = 1;
        for (i=0; i<n; i++)
            if (a[i] < a[k]) ans++;
        printf("%d\n", ans);
    }
    return 0;
}
