#include <cstdio>

const int N = 105;

int n, m;
char board[N][N];

int main() {
  scanf("%d %d", &n, &m);
  for (int i=0; i<n; i++) {
    scanf("%s", board[i]);
    for (int j=0; j<m; j++) {
      if (board[i][j] == '-') continue;
      if ((i + j) & 1) board[i][j] = 'W';
      else board[i][j] = 'B';
    }
    printf("%s\n", board[i]);
  }
  return 0;
}
