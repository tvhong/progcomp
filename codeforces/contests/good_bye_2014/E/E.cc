#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 200500;
const int K = 20;

int n, P[N], L[N], rightmost[N], nxt[K][N], S[K][N], m;
namespace rmq {
    int tree[N*4];

    int get(int ql, int qr, int x = 0, int l = 0, int r = n) {
        //printf("q = (%d %d), x = %d, (%d %d)\n", ql, qr, x, l, r);
        if (ql <= l && qr >= r) return tree[x];
        if (qr <= l || ql >= r || l >= r) return 0;
        if (r - l > 1) {
            int m = (l+r) >> 1;
            return max(get(ql, qr, 2*x+1, l, m), get(ql, qr, 2*x+2, m, r));
        }
        return tree[x];
    }

    void update(int i, int v, int x = 0, int l = 0, int r = n) {
        //printf("i, v = (%d %d), x = %d, (%d %d)\n", i, v, x, l, r);
        if (i < l || i >= r) return;
        if (r - l == 1) {
            tree[x] = v;
            return;
        }
        int m = (l+r) >> 1;
        if (i < m) {
            update(i, v, x*2+1, l, m);
        } else {
            update(i, v, x*2+2, m, r);
        }
        tree[x] = max(tree[x], v);
    }
}

int cost(int x, int y) {
    int res = 0;
    for (int k = K-1; k >= 0; k--) {
        if (nxt[k][x] <= y) {
            res += S[k][x];
            x = nxt[k][x];
        }
    }
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d %d", &P[i], &L[i]);
    }
    for (int i=n-1; i>=0; i--) {
        rightmost[i] = max(
                P[i]+L[i],
                rmq::get(i, upper_bound(P, P+n, P[i]+L[i]) - P)
                );
        rmq::update(i, rightmost[i]);
        nxt[0][i] = upper_bound(P, P+n, rightmost[i]) - P;
        S[0][i] = max(P[nxt[0][i]] - rightmost[i], 0);
        //printf("rightmost[%d]=%d\n", i, rightmost[i]);
        //printf("nxt[0][%d]=%d\n", i, nxt[0][i]);
    }

    nxt[0][n] = n;
    for (int k=1; k<K; k++) {
        nxt[k][n] = n;
        for (int i=0; i<n; i++) {
            nxt[k][i] = nxt[k-1][nxt[k-1][i]];
            S[k][i] = S[k-1][i] + S[k-1][nxt[k-1][i]];
        }
    }
//    for (int i=0; i<n; i++) {
//        for (int k=0; k<K; k++) {
//            printf("nxt[%d][%d] = %d\n", k, i, nxt[k][i]);
//        }
//    }

    scanf("%d", &m);
    for (int i=0; i<m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        x--, y--;
        printf("%d\n", cost(x, y));
    }

    return 0;
}
