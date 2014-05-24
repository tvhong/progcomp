#include <iostream>
#include <limits>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>

#define x first
#define y second
#define mp make_pair
typedef long long ll;

using namespace std;
const ll N = 1e5 + 5;
map<int, vector<int> > b;
int n, m, a[N];
ll sumdiff, diff[N], ans;

int main() {
  cin >> n >> m;
  sumdiff = 0;
  for (int i=0; i<m; i++) {
    cin >> a[i];
    if (i && a[i] != a[i-1]) {
      int tmp = abs(a[i] - a[i-1]);
      sumdiff += tmp;
      diff[a[i]] += tmp;
      diff[a[i-1]] += tmp;

      b[a[i]].push_back(a[i-1]);
      b[a[i-1]].push_back(a[i]);
    }
  }

  ans = sumdiff;
  typedef map<int, vector<int> >::iterator it_type;
  for (it_type it = b.begin(); it != b.end(); ++it) {
    vector<int>& nb = it->y;
    sort(nb.begin(), nb.end());
    int median = nb[nb.size() / 2];
    ll newdiff = 0;
    for (int i=0; i<nb.size(); i++) {
      newdiff += abs(nb[i] - median);
    }
    ans = min(ans, sumdiff + newdiff - diff[it->x]);
  }

  cout << ans << endl;

  return 0;
}
