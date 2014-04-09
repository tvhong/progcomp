#include <bits/stdc++.h>

using namespace std;

const int N = 100000;
const int P = 25;
int a[N];
int p[P];
int d[N][P];

int n, T;
bool isPrime(int n) {
  for (int j=2; j<n; j++) {
    if (n % j == 0) return false;
  }
  return true;
}
void pre() {
  int j = 0;
  for (int i=2; i<100; i++) {
    if (isPrime(i)) p[j++] = i;
  }
  for (int i=0; i<n; i++) {
    int tmp = a[i];
    for (int j = 0; j < P; j++) {
      int cnt = 0;
      while (tmp % p[j] == 0) {
        tmp /= p[j];
        cnt++;
      }
      d[i][j] = i ? d[i-1][j]+cnt : cnt;
    }
  }
}

long long mpow(int a, int b, int m) {
  if (b == 0) return 1;
  long long c = mpow(a, b/2, m);
  return (b&1) ? (c*c*a)%m : (c*c)%m;
}

int main() {
  scanf("%d", &n);
  for (int i=0; i<n; i++) {
    scanf("%d", &a[i]);
  }
  pre();
  /*
  for (int i=0; i<n; i++) {
    for (int j=0; j<P; j++) {
      printf("%d ", d[i][j]);
    }
    printf("\n");
  }
  */
  scanf("%d", &T);
  while (T--) {
    int l, r, m;
    scanf("%d %d %d", &l, &r, &m);
    l--; r--;
    long long ans = 1;
    for (int j=0; j<P; j++) {
      ans = (ans * mpow(p[j], d[r][j] - d[l][j], m)) % m;
    }
    ans = (ans *a[l])%m;
    printf("%lld\n", ans);
  }
  return 0;
}
