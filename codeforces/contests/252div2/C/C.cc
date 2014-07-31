#include <cstdio>
#include <utility>

using namespace std;

#define x first
#define y second
#define mp make_pair

const int N = 305;
typedef pair<int, int> pt;
int n, m, K, k, board[N][N];
pt getnext(pt pos) {
  //printf("testing pos(%d, %d)\n", pos.x, pos.y);
  if (pos.y + 1 <= m && !board[pos.x][pos.y+1]) {
    board[pos.x][pos.y+1] = 1;
    return pt(pos.x, pos.y+1);
  }
  if (pos.y - 1 > 0 && !board[pos.x][pos.y-1]) {
    board[pos.x][pos.y-1] = 1;
    return pt(pos.x, pos.y-1);
  }
  board[pos.x+1][pos.y] = 1;
  return pt(pos.x+1, pos.y);
}

int main() {
  scanf("%d %d %d", &n, &m, &K);

  for (int i =0; i<N; i++)
    for (int j = 0; j<n; j++)
      board[i][j] = 0;


  pt pos(1, 1);
  board[1][1] = 1;
  k = K;
  while (k > 1) {
    printf("2 %d %d", pos.x, pos.y);
    pos = getnext(pos);
    printf(" %d %d\n", pos.x, pos.y);
    pos = getnext(pos);
    k--;
  }
  printf("%d", n*m - 2*(K-1));
  for (int i = 0; i < n*m - 2*(K-1); i++) {
  //while (pos.x > 0 && pos.x <= n && pos.y > 0 && pos.y <= m) {
    printf(" %d %d", pos.x, pos.y);
    pos = getnext(pos);
  }
  printf("\n");
  return 0;
}
