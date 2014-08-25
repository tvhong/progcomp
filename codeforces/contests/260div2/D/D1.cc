#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>

#define x first
#define y second
#define mp make_pair
using namespace std;
const int N = 1e5+5;
const int M = N+100;

int next[M], to[M], start[N], edges;
void add_edge(int u, int v) {
    //printf("add_edge %d %d\n", u, v);
    to[edges] = v;
    next[edges] = start[u];
    start[u] = edges++;
}

int n, k;
map<string, int> ss;
int visited[N];
bool win[N], lose[N];

pair<bool, bool> dfs(int u) {
    if (visited[u]) return mp(win[u], lose[u]);;
    //printf("visiting %d\n", u);
    visited[u] = 1;
    if (start[u] == -1) {
        //printf("ret from %d\n", u);
        return mp(win[u] = false, lose[u] = true);
    }
    win[u] = lose[u] = false;
    for (int e = start[u]; e != -1; e = next[e]) {
        //printf("--child = %d\n", to[e]);
        pair<bool, bool> res = dfs(to[e]);
        win[u] = win[u] || (!res.x);
        lose[u] = lose[u] || (!res.y);
    }
    //printf("ret from %d\n", u);
    return mp(win[u], lose[u]);
}

int main() {
    for (int i=0; i<N; i++) 
        start[i] = -1;
    scanf("%d %d", &n, &k);
    int m = 0;
    for (int i=0; i<n; i++) {
        string str;
        cin >> str;
        while (str.size() > 0) {
            //printf("haha str %s\n", str.c_str());
            if (ss.count(str) == 0) {
                ss[str] = m++;
            }
            str.resize(str.size() - 1);
        }
    }
    typedef map<string, int>::iterator it_type;
    for (it_type it = ss.begin(); it != ss.end(); ++it) {
        string str = it->x;
        str.resize(str.size() - 1);
        if (ss.count(str)) {
            add_edge(ss[str], it->y);
        }
    }
    for (int i=0; i<26; i++) {
        char ch[2] = {'a' + i, 0};
        string str = string(ch);
        if (ss.count(str)) add_edge(m, ss[str]);
    }
    m++;

    dfs(m-1);
    /*
    for (it_type it = ss.begin(); it != ss.end(); ++it) {
        if (!visited[it->y]) {
            dfs(it->y);
        }
    }
    */
    //printf("firstwin = %d\n", firstwin);
    if (win[m-1]) {
        if (lose[m-1]) {
            printf("First\n");
        } else {
            printf("%s\n", (k&1) ? "First" : "Second");
        }
    } else {
        printf("Second\n");
    }
    return 0;
}
