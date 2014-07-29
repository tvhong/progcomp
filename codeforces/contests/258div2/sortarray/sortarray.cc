#include <cstdio>
#include <utility>

const int N = 1e5+5;
int a[N],n;

int main() {
  scanf("%d", &n);
  for (int i=0; i<n; i++) {
    scanf("%d", &a[i]);
  }
  bool dec = false;
  int start = -1, end = -1;
  for (int i=0; i+1<n; i++) {
    if (a[i] > a[i+1]) {
      if (!dec) {
        dec = true;
        start = i;
      }
    } else {
      end = i;
      if (dec) {
        break;
      }
    }
  }
  if (end < start) {
    end = n-1;
  }

  //printf("start=%d, end = %d\n", start, end);
  if (start != -1) {
    bool good = true;
    if (!((start-1 == -1 || a[start-1] < a[end]) &&
        (end+1 == n || a[start] < a[end + 1]))) {
      good = false;
    }
    for (int i=end+1; i+1<n; i++) {
      if (a[i] > a[i+1]) good = false;
    }
    if (good) {
      printf("yes\n%d %d\n", start+1, end+1);
    } else {
      printf("no\n");
    }
  } else {
    printf("yes\n%d %d\n", 1, 1);
  }

  return 0;
}
