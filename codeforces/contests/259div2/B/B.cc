#include <cstdio>
#include <algorithm>

using namespace std;
const int MAX_INT = 1e6;
const int N = 1e5 + 5;
int n, a[N], s, ans;

int main() {
    scanf("%d", &n);
    int mn = MAX_INT;
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        mn = min(mn, a[i]);
    }
    s = 0;
    int cnt = 0;
    while (a[s] != mn || a[s] == a[s ? s-1 : n-1]) {
        s = (s + n - 1) % n;
        //printf("s=%d\n", s);
        ans++;
        cnt++;
        if (cnt == n) {
            printf("0\n");
            return 0;
        }
    }
    int j = s;
    bool good = true;
    for (int i = (s+1)%n; i != s; j=i, i = (i+1)%n) {
        if (a[i] < a[j]) good = false;
    }
    //printf("s = %d, mn = %d\n", s, mn);
    printf("%d\n", good ? ans : -1);

    return 0;
}
