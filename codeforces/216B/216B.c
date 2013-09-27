#include <stdio.h>
#include <string.h>

#define MAX_V 110
#define MAX_E 10010

#define s(n) scanf("%d", &n)
int last[MAX_V], to[MAX_E], next[MAX_E], num_edges;
void add_edge(int u, int v) {
    to[num_edges] = v;
    next[num_edges] = last[u];
    last[u] = num_edges++;
}

int seen[MAX_V];
int dfs(int from) {
    int u = from;
    int depth = 1;
    while (1) {
        seen[u] = 1;
        int wayfrom = 0; //is there a way back to from?
        int e;
        for (e = last[u]; e>=0; e=next[e]) {
            if (to[e] == from) wayfrom = 1;
            if (!seen[to[e]]) {
                u = to[e];
                depth++;
                break;
            }
        }
        if (e < 0) // the last node
            return (wayfrom && depth > 2) ? depth : 0;
    }
}

int main() {
    int n, m, u, v;
    memset(last, -1, sizeof(last)); //set all last to -1
    s(n); s(m);
    while (m--) {
        s(u); s(v);
        u--; v--;
        //printf("add edge %d %d\n", u, v);
        add_edge(u, v);
        add_edge(v, u);
    }

    int cnt = 0;
    for (u=0; u<n; u++) {
        if (!seen[u]) {
            //printf("call dfs on %d\n", u);
            int val = dfs(u);
            if (val&1) cnt++;
            //printf("u=%d, val=%d\n", u, val);
        }
    }
    printf("%d\n", cnt);
    return 0;
}
