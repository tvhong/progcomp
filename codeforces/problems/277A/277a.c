#include <stdio.h>
#include <string.h>

#define MAX_V 110
#define MAX_E 10010


// For constructing graph
int to[MAX_E], next[MAX_E], last[MAX_V], num_edge;
void add_edge(int u, int v) {   
    to[num_edge] = v;
    next[num_edge] = last[u];
    last[u] = num_edge++;
}

int knowsLanguage[MAX_V][MAX_V];

int seen[MAX_V];
void dfs(int i) {
    int j;
    seen[i] = 1;
    for (j=last[i]; j>=0; j=next[j])
        if (!seen[to[j]])
            dfs(to[j]);
}

int main() {
    int n,m,i,j,k,x;
    memset(last, -1, sizeof(last));

    //read input
    scanf("%d%d", &n, &m);
    for (i=0; i<n; i++) {
        scanf("%d", &k);
        for (j=0; j<k; j++) {
            scanf("%d", &x);
            knowsLanguage[i][x-1] = 1;
        }
    }

    int special = 1;
    for (i=0; i<n; i++)
        for (j=0; j<m; j++)
            if (knowsLanguage[i][j])
                special = 0;
    if (special) {
        printf("%d\n", n);
        return 0;
    }

    //constrcut the graph, an edge between 2 ppl if they know a common language
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            for(k=0; k<m; k++)
                if(knowsLanguage[i][k] && knowsLanguage[j][k]) {
                    add_edge(i, j);
                    break;
                }

    int num_components = 0;
    for(i=0; i<n; i++)
        if (!seen[i]) {
            num_components++;
            dfs(i);
        }
    printf("%d\n", num_components - 1);
    return 0;
}
