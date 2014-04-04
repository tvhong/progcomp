#include<bits/stdc++.h>

using namespace std;

const int N = (int)1e5;
int a[N], b[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i=0; i<n; i++) {
    scanf("%d", &a[i]);
    b[i] = a[i];
  }

  sort(b, b+n);
  int cnt = 0;
  for (int i=0; i<n; i++) {
    if (a[i] != b[i]) cnt++;
  }
  printf("%s\n", (cnt>2) ? "NO" : "YES");
  return 0;
}
