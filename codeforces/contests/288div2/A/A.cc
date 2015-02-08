#include <cstdio>

using namespace std;

const int N = 1050;
int n, m, k, a[N][N];

bool blacksquare(int i, int j) {
    if (i <= 0 || j <= 0 || i >= n || j >= m) {
        return false;
    }
    return (a[i][j] && a[i+1][j+1]
            && a[i+1][j] && a[i][j+1]);
}
int main() {
    scanf("%d %d %d", &n, &m, &k);
    int i;
    for (i=1; i<=k; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        a[x][y] = 1;
        if (blacksquare(x-1, y-1) || blacksquare(x-1, y) ||
                blacksquare(x, y-1) || blacksquare(x, y)) {
            printf("%d\n", i);
            break;
        }
    }
    if (i == k+1) {
        printf("0\n");
    }
    return 0;
}
