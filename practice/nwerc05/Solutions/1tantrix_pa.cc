/* Solution to "Tantrix" from NWERC 05
 *
 * Author: Per Austrin
 */
#include <cstdio>
#include <algorithm>

using namespace std;

int neigh[2000][6];

char board[2000][10];
int isforced[2000], forced[2000], nforced;

void initneigh(); // boring stuff... implementation at the end.

bool occ(int p) { return p == -1 ? false : board[p][0]; }

void findforced() {
  nforced = 0;
  memset(isforced, 0, sizeof(isforced));
  for (int i = 0; i < 2000; ++i) {
    if (occ(i)) continue;
    int ns = 0;
    for (int d = 0; d < 6; ++d)
      if (neigh[i][d] != -1 && board[neigh[i][d]][0]) ++ns;
    if (ns >= 3) forced[nforced++] = i, isforced[i] = true;
  }
}

bool canplace(char *piece, int pos) {
  // Can't place where stuff has been placed, doh!
  if (occ(pos)) return false;

  // Rule 1, must place next to played tile.
  bool hasneigh = false;
  for (int d = 0; d < 6; ++d)
    if (occ(neigh[pos][d])) {
      hasneigh = true;
      // Rule 2, colours must match
      if (board[neigh[pos][d]][(d+3)%6] != piece[d])
	return false;
    }
  if (!hasneigh) return false;
  
  for (int d = 0; d < 6; ++d) {
    int np = neigh[pos][d], c = 1;
    if (np != -1) {
      // Rule 5, can't surround forced space with fourth tile
      // (unnecessary, handled by rule 6)
      //      if (isforced[np]) return false;

      // Rule 4, can't create three of same in forced space
      for (int nd = 0; nd < 6; ++nd)
	if (neigh[np][nd] != -1 && 
	    board[neigh[np][nd]][(nd+3)%6] == piece[d])
	  ++c;
      if (c >= 3) return false;

    }
  }

  // Rule 6, can't play controlled side
  // (NB!  Not sure if I interpreted this rule correctly!!)
  for (int d = 0; d < 6; ++d) {
    int np = neigh[pos][d];
    while (np != -1 && !occ(np) &&
	   (occ(neigh[np][(d+2)%6]) || occ(neigh[np][(d+4)%6]))) {
      if (isforced[np])
	return false;
      np = neigh[np][d];
    }
  }

  
  
  return true;
  
}

int main(void) {
  int t, n;
  initneigh();
  for (scanf("%d", &t); t--; ) {
    scanf("%d", &n);
    memset(board, 0, sizeof(board));
    for (int x, y, i = 0; i < n; ++i)
      scanf("%d%d", &x,&y), scanf("%s", board[990-44*y+x]);
    findforced();

    char piece[10];
    int res[2]; // res[1] == possible forced moves, res[0] = non-forced.
    res[0] = res[1] = 0;
    for (int i = 0; i < 5; ++i) {
      scanf("%s", piece);
      for (int r = 0; r < 6; ++r) {
	for (int pos = 0; pos < 2000; ++pos)
	  res[isforced[pos]] += canplace(piece, pos);
	rotate(piece, piece+1, piece+6);
      }
    }
    // Rule 3, choose forced moves if possible
    if (res[1]) printf("%d\n", res[1]);
    else printf("%d\n", res[0]);
  }
  return 0;
}



void initneigh() {
  const int dx[] = {0, 1, 1, 0, -1, -1};
  const int dy[] = {-1, 0, 1, 1, 0, -1};
  memset(neigh, -1, sizeof(neigh));
  for (int y = 0; y < 44; ++y)
    for (int x = 0; x < 44; ++x)
      for (int d = 0; d < 6; ++d) {
	int nx = x + dx[d], ny = y + dy[d];
	if (nx >= 0 && nx < 44 && ny >= 0 && ny < 44)
	  neigh[y*44+x][d] = ny*44+nx;
      }
}
