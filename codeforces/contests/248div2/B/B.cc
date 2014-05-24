#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 5;
long long n, m, cost[N], sorted_cost[N], sum[N], sum2[N];

int main() {
  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> cost[i];
    sorted_cost[i] = cost[i];
    sum[i] = cost[i];
    if (i) sum[i] += sum[i-1];
    //printf("sum[%d] = %d\n", i, sum[i]);
  }

  sort(sorted_cost, sorted_cost + n);
  for (int i=0; i<n; i++) {
    sum2[i] = sorted_cost[i];
    if (i) sum2[i] += sum2[i-1];
  }

  cin >> m;
  for (int i=0; i<m; i++) {
    bool good = true;
    long long t, l, r, ans;
    cin >> t >> l >> r;
    l--, r--;
    if (t == 1) {
      if (l) ans = sum[r] - sum[l-1];
      else ans = sum[r];
    } else {
      if (l) ans = sum2[r] - sum2[l-1];
      else ans = sum2[r];
    }
    cout << ans << endl;
  }
  return 0;
}
