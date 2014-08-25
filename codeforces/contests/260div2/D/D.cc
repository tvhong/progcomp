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
const int M = N;

int next[M], to[M], start[N], edges;
void add_edge(int u, int v) {
    to[edges] = v;
    next[edges] = start[u];
    start[u] = edges++;
}

int n, k;
map<string, int> ss;
int visited[N];
bool dp[N];

bool dfs(int u) {
    //printf("visiting %d\n", u);
    if (visited[u]) return dp[u];
    visited[u] = 1;
    if (start[u] == -1) return dp[u] = true;
    dp[u] = true;
    for (int e = start[u]; e != -1; e = next[e]) {
        //printf("--child = %d\n", to[e]);
        if (dfs(to[e])) {
            dp[u] = false;
            break;
        }
    }
    return dp[u];
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
        //cout << "before: " << str << endl;
        str.resize(str.size() - 1);
        //cout << "after: " << str << endl;
        if (ss.count(str)) {
            add_edge(ss[str], it->y);
        }
    }
    //printf("edges = %d\n", edges);
    bool firstwin = false;
    bool absolute_win = false;
    for (it_type it = ss.begin(); it != ss.end() && !absolute_win; ++it) {
        if (!visited[it->y]) {
            //printf("start from %d\n", it->y);
            bool res = dfs(it->y);
            if ((it->x).length() == 1 && res) {
                firstwin = firstwin || res;
                for (int e = start[u]; e != -1; e = next[e]) {
                    if (dp[to[e]]) absolute_win = true;
                }
            }
        }
    }
    //printf("firstwin = %d\n", firstwin);
    if (absolute_win) {
        printf("First\n");
    } else if (firstwin) {
        printf("%s\n", (k&1) ? "First" : "Second");
    } else {
        printf("Second\n");
    }
    return 0;
}
