#include <iostream>
#include <cmath>

using namespace std;
int n, m;
double cur, prev, ans;
int main() {
  cin >> m >> n;
  cur = prev = ans = 0;
  for (int i=1; i<=m; i++) {
    cur = pow(i*1.0/m, n);
    ans += i * (cur - prev);
    prev = cur;
  }
  cout << ans << endl;
  return 0;
}
