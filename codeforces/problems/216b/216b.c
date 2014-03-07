#include <stdio.h>

#define s(n) scanf("%d", &n)
#define MAX_N 110
#define MAX_E MAX_N*2

int last[MAX_N], next[MAX_E], to[MAX_E], num_edge;

int main() {
    int N, M, i, u, v;
    int g[MAX_N];
    s(N); s(M);
    for (i = 0; i < N; i++) {
        g[i] = -1;
    }
    int cnt = 0;
    while (M--) {
        enemy[][0]
    }
    
    while (M--) {
        s(u); s(v);
        u--; v--;
        if (g[u] == -1 && g[v] == -1) {
            g[u] = 0;
            g[v] = 1;
        } else if (g[u] == -1) {
            g[u] = (g[v])?0:1;
        } else if (g[v] == -1) {
            g[v] =  (g[u])?0:1;
        } else if (g[u] == g[v]){
            cnt++;
        }
    }
    /*
    for (i = 0; i<N; i++) {
        printf("%d\n", g[i]);
    }
    */
    printf("%d\n", cnt);
    return 0;
}
