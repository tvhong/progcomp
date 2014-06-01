#include <bits/stdc++.h>

#define x first
#define y second
#define mp make_pair
using namespace std;

typedef unsigned int uint;
const int N = 1005;
int T, n, m, k, covered, seen[N*N];
int board[N][N];
int dx[4] = {-1,1, 0, 0};
int dy[4] = {0,0, -1, 1};
bool validi(int x) {
  return x >= 0 && x <n;
}
bool validj(int x) {
  return x >= 0 && x <m;
}
bool DFS(pair<int, int> pt) {
  if (seen[pt.x * m + pt.y]) return true;
  seen[pt.x*m + pt.y] = 1;
  covered++;
  if (pt.x == 0 || pt.x == n-1 || pt.y == 0 || pt.y == m-1)
    return false;
  for (int kk = 0; kk<4; kk++) {
    pair<int, int> pt2 = pt;
    pt2.x += dx[kk];
    pt2.y += dy[kk];
    if (board[pt2.x][pt2.y]) continue;
    if (validi(pt2.x) && validj(pt2.y)) {
      bool good = DFS(pt2);
      if (!good) return false;
    }
  }
  return true;
}

int main() {
  scanf("%d", &T);
  for (int t=1; t<=T; t++) {
    printf("Case #%d: ", t);
    scanf("%d %d %d", &n, &m, &k);
    for (int i=0; i<n; i++)
      memset(board[i], 0, sizeof board[i]);
    for (uint st = 0; st < (1<<(n*m)); st++) {
      //printf("st=%d\n", st);
      if (st == 10000) break;
      pair<int, int> pos;
      int x = 0, y = -1;
      int cnt = 0;
      for (uint j=0; j < n*m; j++) {
        y++;
        if (y == m) y=0, x++;
        if (st&(1<<j)) {
          cnt++;
          pos = mp(x, y);
          board[x][y] = 1;
        } else {
          board[x][y] = 0;
        }
      }
      /*
      for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) 
          printf("%d ", board[i][j]);
        printf("\n");
      }
      printf("\n");
      */
      if (cnt > k) continue;
      for (int kk = 0; kk<4; kk++) {
        pair<int, int> pt = pos;
        pt.x += dx[kk];
        pt.y += dy[kk];
        covered = 0;
        if (validi(pt.x) && validj(pt.y)) {
          memset(seen, 0, sizeof seen);
          if (DFS(pt)) {
            cnt += covered;
          }
        }
      }
    }
  }
  return 0;
}
