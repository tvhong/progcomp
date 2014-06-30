/* Solution to "Bowlstack" from NWERC 2005.
 * Author: Per Austrin. */
#include <algorithm>
#include <iostream>
using namespace std;
int i, j, t, n, I[11];
double mx, bx, x[11], h[11], r[11], R[11];
double dh(int i, int j) {
  return r[i] > R[j] ? h[j] : R[i] <= r[j] ? 0 :
    max(r[i] > r[j] ? (r[i]-r[j]) * h[j] / (R[j]-r[j]) : 0,
	R[i] < R[j] ? (R[i]-r[j]) * h[j] / (R[j]-r[j]) - h[i] :
	R[i] > r[i] ? h[j] - (R[j]-r[i]) * h[i] / (R[i]-r[i]) : 0);
}
double H() {
  for (mx = i = 0; x[i] = 0, i < n && mx < bx; mx >?= x[i]+h[I[i]], ++i)
    for (j = 0; x[i] >?= x[j] + dh(I[i], I[j]), j < i; ++j);
  return mx;
}
main(void) {
  for (cin >> t; cin >> n, bx = 1e99, t--; ) {
    for (i = 0; i < n; ++i) I[i] = i, cin >> h[i] >> r[i] >> R[i];
    do bx <?= H(); while (next_permutation(I, I+n));
    cout << (int)bx << endl;
  }
}
