#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 9;
const int MAX_HEIGHT = 1000*10;
int order[N], n;
double ans;
struct bowl {
  int h, r, R;
} bowl[N];

double cal_d(int r, int R, int l) {
  return 1.0*h*(l+r+R) / r;
}
double get_height() {
  double height = bowl[order[0]];
  for (int i=1; i<n; i++) {
    for (int j=0; j<i; j++) {
      struct bowl lb = bowl[order[j]];
      struct bowl hb = bowl[order[i]];
      if (hb.r > lb.R) {
        nheight = h1 + h2;
      } else if (

    }
  }
  return height;
}

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i=0; i<n; i++)
      order[i] = i;
    for (int i=0; i<n; i++) {
      scanf("%d %d %d", &bowl[i].h, &bowl[i].r, &bowl[i].R);
    }

    ans = MAX_HEIGHT;
    do {
      double height = get_height();
      ans = min(ans, height);
    } while (next_permutation(order, order+n));
  }
}
