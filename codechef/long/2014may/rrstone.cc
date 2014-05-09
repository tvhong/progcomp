#include <bits/stdc++.h>

using namespace std;
const int N = 100005;
int n, k;
long long a[N];
void stoning() {
  long long mx = a[0];
  for (int i=0; i<n; i++)
    mx = max(mx, a[i]);
  for (int i=0; i<n; i++)
    a[i] = mx - a[i];
}
int main() {
  scanf("%d %d", &n, &k);
  for (int i=0; i<n; i++) {
    scanf("%lld", &a[i]);
  }
  if (k) {
    stoning();
    if (!(k&1))
      stoning();
  }
  for (int i=0; i<n; i++)
    printf("%lld%c", a[i], (i==n-1) ? '\n' : ' ');
  return 0;
}
