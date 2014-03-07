#include <stdio.h>
#include <string.h>

#define s(n) scanf("%d", &n)
#define max(a, b) (a > b) ? a : b

#define NUM_V 2000
#define NUM_E 2000
int to[NUM_E], next[NUM_E], last[NUM_V], num_edges;
void add_edge(int i, int j) {
    to[num_edges] = j;
    next[num_edges] = last[i];
    last[i] = num_edges++;
}
int seen[NUM_V];

int dfs(int i, int d) {
    seen[i] = 1;
    //printf("i=%d\n", i);
    int e;
    int ret = d;
    for (e=last[i]; e>=0; e=next[e]) {
        if (!seen[to[e]]) {
            //printf("from %d call %d\n", i, to[e]);
            int val = dfs(to[e], d+1);
            ret = max(ret, val);
        }
    }
    return ret;
}

int count_depth(int i) {
    return dfs(i, 1);
}

int main() {
    int n, i;
    s(n);
    memset(last, -1, sizeof(last));
    int p[NUM_V];
    for(i=0; i<n; i++) {
        s(p[i]);
        if (p[i] != -1) add_edge(--p[i], i);
    }
    int max_depth = 0;
    for(i=0; i<n; i++) {
        if (p[i] == -1) {
            //printf("Start at %d\n", i);
            int depth = count_depth(i);
            //printf("stoped");
            if (depth > max_depth) max_depth = depth;
        }
    }
    printf("%d\n", max_depth);
    return 0;
}
