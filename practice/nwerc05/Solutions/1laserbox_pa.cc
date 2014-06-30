/* Solution to "Laserbox" from NWERC 2005.
 * Author: Per Austrin. */
#include <cstdio>
main() {
  int t, n, r, x, y, dx, dy, trn[60][60];
  for (scanf("%d", &t); scanf("%d%d", &n, &r), t--; printf("%d %d\n", x, y)) {
    for (int i = 0; i <= r && scanf("%d%d", &x, &y); ++i) trn[y][x] = t+1;
    for (dx = x ? x <= n ? 0 : -1 : 1, dy = y ? y <= n ? 0 : -1 : 1;
	 (x += dx) && (y += dy) && x <= n && y <= n;
	 dy = trn[y][x]==t+1 ? -(dy ^= dx ^= dy ^= dx) : dy);
  }
}
