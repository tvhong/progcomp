#include <cstdio>

#define SIZE 1000010
//#define SIZE 100000
#define s(x) scanf("%d", &x);

using namespace std;

int main() {
    int n, k, i;
    int a[SIZE];
    int ju[SIZE];

    scanf("%d %d", &n, &k);
    for (i=0; i<n; i++) {
        scanf("%d", &a[i]);
        ju[i] = -1;
    }

    long long ans = 1;
    for (i = n-2; i>=0; i--){ 
        int j = i+1;
        while (j!=-1 && a[j] >= a[i])
            j = ju[j];

        ju[i] = j;
        int fear = (ju[i] == -1) ? 1 : (ju[i] - i + 1);
        ans *= fear;
        ans %= 1000000007;
    }

    /*
    for (i=0; i<n; i++)
        printf("%d\n", ju[i]);
        */
    printf("%lld\n", ans);
    return 0;
}
