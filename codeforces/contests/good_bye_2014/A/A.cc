#include <cstdio>

using namespace std;
const int N = 3e4 + 5;
int n, t, a[N];

int main() {
    scanf("%d %d", &n, &t);
    for (int i=1; i<n; i++) {
        scanf("%d", &a[i]);
    }
    int pos = 1;
    while (pos < t) {
        pos = pos + a[pos];
    }
    printf("%s\n", pos == t ? "YES" : "NO");
    return 0;
}
