#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;

#define x first
#define y second
#define mp make_pair
const int N = 1e6+5;
int n, k1, k2;
pair<int, int> t[N];
int main() {
  int T = 0;
  while (scanf("%d %d %d", &n, &k1, &k2), n != 0 && k1 != 0 && k2 != 0) {
    T++;
    for (int i=1; i<=n; i++) {
      scanf("%d", &t[i].x);
      t[i].y = i;
    }
    sort(t+1, t+1+n);
    printf("Case %d\n", T);
    vector<int> res;
    for (int i=1; i<=k1; i++) {
      res.push_back(t[i].y);
    }
    sort(res.begin(), res.end());
    for (int i=0; i<res.size(); i++) {
      printf("%d%c", res[i], (i==res.size()-1) ? '\n' : ' ');
    }

    res.clear();
    for (int i=1; i<=k2; i++) {
      res.push_back(t[n-i+1].y);
    }
    sort(res.begin(), res.end(), greater<int>());
    for (int i=0; i<res.size(); i++) {
      printf("%d%c", res[i], (i==res.size()-1) ? '\n' : ' ');
    }
  }
}
