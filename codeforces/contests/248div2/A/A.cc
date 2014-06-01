#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1000;
int n, a[N];

int main() {
  scanf("%d", &n);
  bool has_one = false;
  int sum = 0;
  for (int i=0; i<n; i++) {
    scanf("%d", &a[i]);
    a[i] /= 100;
    sum += a[i];
    if (a[i] == 1) has_one = true;
  }
  if (sum&1) {
    printf("NO\n");
  } else {
    printf("%s\n", (!((sum>>1)&1) || has_one) ? "YES" : "NO");
  }
  return 0;
}
