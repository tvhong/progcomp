#include <cstdio>
#include <algorithm>

#define x first
#define y second
using namespace std;

typedef pair<int, int> Seg;
const int N = 5e7;
int t, n, k, p;
Seg a[N], b[N];

bool solve() {
  bool good = true;
  int i = 0;
  int j = 0;
  /*
  if (b[0].x == 1)
    j = 0;
  else 
    j = p-1;
    */
  while (i < k) {
    printf("i=%d j=%d\n", i, j);
    int end1 = a[i].y;
    int end2 = b[j].y;
    if (b[j].y < b[j].x) {
      if (a[i].x <= b[j].y) {
      } else if (a[i].x{
      }

      if (a[i].y < a[i].x) {

      }
    }
    if (a[i].y < a[i].x) {
      end1 += n;
      if (b[j].y < b[j].x) end2 += n;
    }
    if (a[i].y < b[j].y) i++;
    else if (a[i].y == b[j].y) i++, j=(j+1)%p;
    else return false;
  }

  return true;
}
int main() {
  scanf("%d", &t);
  printf("haha\n");
  while (t--) {
    scanf("%d %d %d", &n, &k, &p);
    for (int i=0; i<k; i++)
      scanf("%d %d", &a[i].x, &a[i].y);
    for (int i=0; i<p; i++) {
      scanf("%d %d", &b[i].x, &b[i].y);
      //if (b[i].y > b[i].x) b[i].x += n;
    }
    sort(a, a+k);
    sort(b, b+p);
    printf("%s\n", (solve()) ? "Yes" : "No");
  }
  return 0;
}
