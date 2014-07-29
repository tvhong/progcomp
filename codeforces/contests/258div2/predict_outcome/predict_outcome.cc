#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
ll n, k, d1, d2, x1, x2, x3;

int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> k >> d1 >> d2;
    bool good = false;
    for (int i=-1; i<=1; i++) {
      for (int j=-1; j<=1; j++) {
        if (i == 0 || j == 0) continue;
        x3 = 0;
        x2 = x3 + i*d2;
        x1 = x2 + j*d1;
        ll m = min(min(x1, x2), x3);
        x1 -= m; x2 -= m; x3 -= m;
        //cout << "x1=" << x1 << ", x2=" << x2 << ", x3=" << x3 << endl;
        if (x1 + x2 + x3 > k) {
          //cout << "passed" << endl;
          continue;
        }
        ll mx = max(max(x1, x2), x3);
        if ((x1+x2+x3) % 3 == k % 3) {
          ll needing = 3*mx - (x1+x2+x3); 
          if (n-k >= needing && (n-k-needing)%3 == 0) {
            good = true;
          }
        }
      }
    }
    printf("%s\n", good ? "yes" : "no");
  }
  return 0;
}
