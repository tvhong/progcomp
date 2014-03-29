#include <cstdio>
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
int strong[N];
int strongf[N];
int val[N];
int n, k, m, cnt, tt;

int main() {
  while (scanf("%d %d", &n, &k), n) {
    memset(troops, 0, sizeof troops);
    cnt = 0;
    tt = 0;
    edges = 0;
    memset(last, -1, sizeof last);
    //memset(strongf, 0, sizeof strongf);
    //memset(val, 0, sizeof strongf);

    for (int i=0; i<n; i++) {
      scanf("%d %d", &troops[i], &m);
      val[i] = troops[i];
      if (troops[i] >= k) {
        strong[cnt++] = i;
        strongf[i] = 1;
        tt += troops[i];
      }
      for (int j=0; j < m; j++) {
        int y;
        scanf("%d", &y);
        add(i, y);
      }
    }

    for (int i=0; i<cnt; i++) {
      //int val = troops[strong[i]];
      for (int v=last[strong[i]]; v!=-1; v= next[v]) {
        if (strongf[to[v]]) continue;
        val[to[v]] += troops[strong[i]];
        if (val[to[v]] >= k) {
          strong[cnt++] = to[v];
          strongf[to[v]] = 1;
          tt += troops[to[v]];
        }
      }
    }
    /*
    for (int i=0; i<n; i++) {
      //cout << i << endl;
      int val = troops[i];
      for (int v=last[i]; v!=-1; v= next[v]) {
        if (strong[to[v]])
          val += troops[to[v]];
      }
      if (val >= k) {
        cnt++;
        tt += troops[i];
      }
    }
    */
    printf("%d %d\n", cnt, tt);
  }
  return 0;
}
