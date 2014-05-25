#include <cstdio>
#include <map>

#define x first
#define y second
#define mp make_pair
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
int T, n, a[N];
int sum[N];
map<int, int> remainder;
int main() {
  scanf("%d", &T);
  while (T--) {
    remainder.clear();
    int x, y;
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
      scanf("%d", &a[i]);
      sum[i] = a[i];
      if (i > 1) sum[i] += sum[i-1];
      sum[i] %= n;
      //printf("sum[%d] = %d\n", i, sum[i]);
    }
    x = y = -1;
    for (int i=1; i<=n; i++) {
      if (sum[i] == 0) {
        x = 1;
        y = i;
        break;
      } else if (remainder.count(sum[i]) > 0) {
        x = remainder[sum[i]] + 1;
        y = i;
        break;
      }
      remainder[sum[i]] = i;
    }
    printf("%d\n", y-x+1);
    for (int i=x; i<=y; i++)
      printf("%d%c", i, (i==y) ? '\n' : ' ');
  }
  return 0;
}
