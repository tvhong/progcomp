#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;
const int N = 1000 + 5;
const int T = 10000;

int next[2*N*N], to[2*N*N], last[N], edges;
void add(int u, int v) {
  next[edges] = last[u];
  to[edges] = v;
  last[u] = edges++;
}

int troops[N];
queue<int> weak;
int val[N];
int visited[N];
int n, k, m, cnt, tt;

int main() {
  while (scanf("%d %d", &n, &k), n) {
    memset(troops, 0, sizeof troops);
    cnt = 0;
    tt = 0;
    edges = 0;
    memset(last, -1, sizeof last);
    memset(visited, 0, sizeof visited);

    for (int i=0; i<n; i++) {
      scanf("%d %d", &troops[i], &m);
      val[i] = troops[i];
      /*
      if (troops[i] >= k) {
        tt += troops[i];
      }
      */
      for (int j=0; j < m; j++) {
        int y;
        scanf("%d", &y);
        add(i, y);
      }
    }
    for (int u = 0; u < n; u++) {
      val[u] = troops[u];
      for (int e = last[u]; ~e; e = next[e]) {
        val[u] += troops[to[e]];
      }
      if (val[u] < k) {
        weak.push(u);
        visited[u] = 1;
      }
    }
    while (!weak.empty()) {
      int u = weak.front();
      weak.pop();
      for (int e=last[u]; ~e; e = next[e]) {
        int v = to[e];
        if (visited[v]) continue;
        val[v] -= troops[u];
        if (val[v]<k) {
          weak.push(v);
          visited[v] = 1;
        }
      }
    }
    for (int i=0; i<n; i++) {
      if (!visited[i]) {
        cnt++;
        tt += troops[i];
      }
    }
    printf("%d %d\n", cnt, tt);
  }
  return 0;
}
