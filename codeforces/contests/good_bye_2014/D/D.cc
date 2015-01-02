#include <cstdio>
#include <cstring>

typedef long long ll;
using namespace std;

const int N = 1e5+5;

int n, q, children[N], c;
double avg_cost;

int last[2*N], next[2*N], to[2*N], weight[2*N], used[2*N], m;
void add_edge(int u, int v, int w) {
    to[m] = v;
    next[m] = last[u];
    weight[m] = w;
    last[u] = m++;
}

long long triple(int n) {
    return n < 3 ? 0 : (ll)n * (n-1) * (n-2);
}
double p2(int nl, int nr) {
    ll tmp = triple(n);
    return 1.0 - triple(nl)*1.0/tmp - triple(nr)*1.0/tmp;
}

int calc_children(int u) {
    //printf("u = %d\n", u);
    for (int e = last[u]; e != -1; e = next[e]) {
        if (used[e]) continue;
        int v = to[e];
        used[e] = 1;
        used[e^1] = 2;
        children[u] += calc_children(v) + 1;
    }

    return children[u];
}

double edge_cost(int e, int val) {
    if (used[e] == 2) e = e^1;

    int below = children[to[e]] + 1;
    int above = n - below;

    return p2(below, above) * (val << 1);
}

int main() {
    memset(last, -1, sizeof(last));
    scanf("%d", &n);
    for (int i=0; i<n-1; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        x--, y--;
        add_edge(x, y, z);
        add_edge(y, x, z);
    }

    calc_children(0);

//    for (int i=0; i<n; i++) {
//        printf("%d\n", children[i]);
//    }

    for (int i=0; i<n-1; i++) {
        int e = i<<1;
        avg_cost += edge_cost(e, weight[e]);
    }

    //printf("avg_cost = %f\n", avg_cost);

    scanf("%d", &q);
    for (int i=0; i<q; i++) {
        int r, w;
        scanf("%d %d", &r, &w);
        r--;
        int e = r<<1;
        //printf("weight[e] = %d\n", weight[e]);
        avg_cost -= edge_cost(e, weight[e] - w);
        weight[e] = w;
        weight[e^1] = w;
        printf("%.9f\n", avg_cost);
    }

    return 0;
}
